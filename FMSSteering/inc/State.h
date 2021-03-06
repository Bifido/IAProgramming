#pragma once
#include "FSMCore.h"
#include <string>

template<typename Agent>
class State
{
public:
	virtual void OnEnter(Agent&) const = 0;
	virtual void OnExit(Agent&) const = 0;
	virtual void Update(Agent&, float) const = 0;
	virtual FSMStates CheckTransition(Agent&) const = 0;
	virtual std::string GetStateName() const = 0;

protected:
	State() { }
	virtual ~State() { }
};

