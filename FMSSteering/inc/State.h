#pragma once

template<typename Agent>
class State
{
public:
	State() { }
	virtual ~State() { }

	virtual void OnEnter(Agent*) = 0;
	virtual void OnExit(Agent*) = 0;
	virtual void Update(Agent*) = 0;
	virtual State* CheckTransition() = 0;
};

