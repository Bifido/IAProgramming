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
		FSMStates newState = (sharedStates.GetGlobalArc() != nullptr) ? sharedStates.GetGlobalArc()->CheckTransition(actualAgent) : FSMCore<Agent>::GetNotValidState();
		if (FSMCore<Agent>::IsStateValid(newState) && sharedStates.GetState(newState) != actualState)
		{
			actualState->OnExit(actualAgent);
			actualState = sharedStates.GetState(newState);
			actualState->OnEnter(actualAgent);
		}
		
		{
			// Check if the FSM changes state
			newState = actualState->CheckTransition(actualAgent);

			// If new state is changed, changing state!
			if (FSMCore<Agent>::IsStateValid(newState) && sharedStates.GetState(newState) != actualState){
				actualState->OnExit(actualAgent);
				actualState = sharedStates.GetState(newState);
				actualState->OnEnter(actualAgent);
			}
		}

		// Update acual state
		actualState->Update(actualAgent);
	}

}