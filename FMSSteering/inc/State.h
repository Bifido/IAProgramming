#pragma once
#include "FSMCore.h"

template<typename Agent>
class State
{
public:
	virtual void OnEnter(Agent&) const = 0;
	virtual void OnExit(Agent&) const = 0;
	virtual void Update(Agent&) const = 0;
	virtual int CheckTransition(Agent&) const = 0;

protected:
	State() { }
	virtual ~State() { }
};

