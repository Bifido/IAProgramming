#pragma once
#include "FSMCore.h"

template<typename Agent>
class State
{
public:
	State(const FSMCore < Agent > & fsmCore) : m_fsmCore(fsmCore){ }
	virtual ~State() { }

	virtual void OnEnter(const Agent*) = 0;
	virtual void OnExit(const Agent*) = 0;
	virtual void Update(const Agent*) = 0;
	virtual State* CheckTransition(const Agent*) const = 0;

protected:
	const FSMCore<Agent>& m_fsmCore;
};

