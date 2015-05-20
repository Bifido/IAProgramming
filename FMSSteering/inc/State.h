#pragma once
#include "FSMCore.h"

template<typename Agent>
class State
{
public:
	State(const FSMCore < Agent > & fsmCore) : m_fsmCore(fsmCore){ }
	virtual ~State() { }

	virtual void OnEnter(Agent*) const = 0;
	virtual void OnExit(Agent*) const = 0;
	virtual void Update(Agent*) const = 0;
	virtual State* CheckTransition(Agent*) const = 0;

protected:
	const FSMCore<Agent>& m_fsmCore;
};

