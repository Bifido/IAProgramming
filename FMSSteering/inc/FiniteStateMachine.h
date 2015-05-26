#include "State.h"
#include "GlobalArc.h"
#include "FSMCore.h"

/**
	State must implement 
		OnEnter();
		OnExit();
		Update();
		CheckTransition();
*/
template <typename Agent, int I>
class FiniteStateMachine
{
	FSMCore<Agent, I>& sharedStates;
	State<Agent>* actualState;
public:
	FiniteStateMachine();
	~FiniteStateMachine();

	void Run(Agent& actual);
};



// ***********************************************************************************************************
// ******************************************* IMPLEMENTATIONS ***********************************************
// ***********************************************************************************************************

template<typename Agent, int I>
FiniteStateMachine<Agent,I>::FiniteStateMachine() :
	sharedStates(FSMCore<Agent, I>::GetInstance())
{
	actualState = sharedStates.GetDefaultState();
};

template<typename Agent, int I>
FiniteStateMachine<Agent,I>::~FiniteStateMachine() { };

template<typename Agent, int I>
void FiniteStateMachine<Agent,I>::Run(Agent& actualAgent){

	if (actualState != nullptr){

		// Check if the FSM changes state 
		// if no globalArc => the state remain the same!
		FSMStates newState = (sharedStates.GetGlobalArc() != nullptr) ? sharedStates.GetGlobalArc()->CheckTransition(actualAgent) : FSMCore<Agent, I>::GetNotValidState();
		if (FSMCore<Agent, I>::IsStateValid(newState) && sharedStates.GetState(newState) != actualState)
		{
			actualState->OnExit(actualAgent);
			actualState = sharedStates.GetState(newState);
			actualState->OnEnter(actualAgent);
		}
		
		{
			// Check if the FSM changes state
			newState = actualState->CheckTransition(actualAgent);

			// If new state is changed, changing state!
			if (FSMCore<Agent, I>::IsStateValid(newState) && sharedStates.GetState(newState) != actualState){
				actualState->OnExit(actualAgent);
				actualState = sharedStates.GetState(newState);
				actualState->OnEnter(actualAgent);
			}
		}

		// Update acual state
		actualState->Update(actualAgent);
	}

}