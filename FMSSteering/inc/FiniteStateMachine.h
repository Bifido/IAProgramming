#include "State.h"
#include "GlobalArc.h"
#include "FSMCore.h"
//template<typename Agent>
//class State;
//template<typename Agent>
//class GlobalArc;
//template<typename Agent>
//class FSMCore;

/**
	Stato must implement 
		OnEnter();
*/
template <typename Agent>
class FiniteStateMachine
{
	FSMCore<Agent>& sharedStates;
	State<Agent>* actualState;
	GlobalArc<Agent>* globalArc;
public:
	FiniteStateMachine();
	~FiniteStateMachine();

	void Run(Agent& actual);
};



// ***********************************************************************************************************
// ******************************************* IMPLEMENTATIONS ***********************************************
// ***********************************************************************************************************

template<typename Agent>
FiniteStateMachine<Agent>::FiniteStateMachine(): 
	sharedStates(FSMCore<Agent>::GetInstance())
{
	actualState = sharedStates.GetDefaultState();
};

template<typename Agent>
FiniteStateMachine<Agent>::~FiniteStateMachine() { };

template<typename Agent>
void FiniteStateMachine<Agent>::Run(Agent& actualAgent){

	if (actualState != nullptr){

		// Check if the FSM changes state 
		// if no globalArc => the state remain the same!
		FSMCore<Agent>::States newState = (globalArc != nullptr) ? 
			static_cast<FSMCore<Agent>::States>(globalArc->CheckTransition(actualAgent)) : FSMCore<Agent>::NOT_VALID;
		if (newState != FSMCore<Agent>::NOT_VALID)
		{
			actualState->OnExit(actualAgent);
			actualState = sharedStates.GetState(newState);
			actualState->OnEnter(actualAgent);
		}
		else
		{
			// Check if the FSM changes state
			newState = static_cast<FSMCore<Agent>::States>(actualState->CheckTransition(actualAgent));

			// If new state is changed, changing state!
			if (sharedStates.GetState(newState) != actualState){
				actualState->OnExit(actualAgent);
				actualState = sharedStates.GetState(newState);
				actualState->OnEnter(actualAgent);
			}
		}

		// Update acual state
		actualState->Update(actualAgent);
	}

}