#include <list>

/**
	Stato must implement 
		OnEnter();
*/
template <typename Stato>
class FiniteStateMachine{
	std::list<Stato*> actualState;
public:
	FiniteStateMachine();
	~FiniteStateMachine();

	void Run();
	void ChangeState(Agent)
};

