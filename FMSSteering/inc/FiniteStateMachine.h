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

	void Run(Agent* actual);
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
void FiniteStateMachine<Agent>::Run(Agent* actualAgent){

	if (actualState != nullptr){

		// Check if the FSM changes state 
		// if no globalArc => the state remain the same!
		State<Agent>* newState = globalArc != nullptr ? globalArc->CheckTransition(*actualAgent) : actualState;
		if (newState != actualState)
		{
			actualState->OnExit(*actualAgent);
			actualState = newState;
			actualState->OnEnter(*actualAgent);
		}
		else
		{
			// Check if the FSM changes state
			newState = actualState->CheckTransition(*actualAgent);

			// If new state is changed, changing state!
			if (newState != actualState){
				actualState->OnExit(*actualAgent);
				actualState = newState;
				actualState->OnEnter(*actualAgent);
			}
		}

		// Update acual state
		actualState->Update(*actualAgent);
	}

}