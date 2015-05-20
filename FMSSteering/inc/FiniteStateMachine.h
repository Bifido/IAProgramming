#include <list>
//#include "State.h"

template<typename Agent>
class State;
template<typename Agent>
class FSMCore;

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
		// Check if the FSM chenges state
		State<Agent>* newState = actualState->CheckTransition();

		// If new state is changed, changing state!
		if (newState != actualState){
			 actualState->OnExit();
			 actualState = newState;
			 actualState->OnEnter();
		}

		// Update acual state
		actualState->Update();
	}

}