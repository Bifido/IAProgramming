#pragma once
#include "FSMCore.h"

template<typename Agent>
class State;


template<typename Agent>
class GlobalArc
{
public:

	virtual FSMStates CheckTransition(Agent&) const = 0;

protected:
	GlobalArc(){};
	virtual ~GlobalArc() {};
};