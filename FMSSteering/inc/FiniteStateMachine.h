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
	void ChangeState(Agent)
};

