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

	void Run();
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
void FiniteStateMachine<Agent>::Run(){

	if (actualState != nullptr){

		// Check if the FSM changes state
		State<Agent>* newState = globalArc->CheckTransition();
		if (newState != nullptr)
		{
			actualState->OnExit();
			actualState = newState;
			actualState->OnEnter();
		}
		else
		{
			// Check if the FSM changes state
			newState = actualState->CheckTransition();

			// If new state is changed, changing state!
			if (newState != actualState){
				actualState->OnExit();
				actualState = newState;
				actualState->OnEnter();
			}
		}

		// Update acual state
		actualState->Update();
	}

}