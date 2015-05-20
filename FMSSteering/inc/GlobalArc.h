#pragma once

template<typename Agent>
class State;
template<typename Agent>
class FSMCore;

template<typename Agent>
class GlobalArc
{
public:
	GlobalArc(const FSMCore < Agent > & fsmCore) : m_fsmCore(fsmCore){ }
	virtual ~GlobalArc() { }

	virtual State<Agent>* CheckTransition(const Agent*) const = 0;

protected:
	GlobalArc(){};
	const FSMCore<Agent>& m_fsmCore;
};