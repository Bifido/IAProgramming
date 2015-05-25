#pragma once
#include "GlobalArc.h"

class NanoAgent;

class GlobalNano : public GlobalArc<NanoAgent>
{
public:
	GlobalNano();
	~GlobalNano();

	FSMStates CheckTransition(NanoAgent& agent) const;
};

