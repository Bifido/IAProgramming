#pragma once
#include "GlobalArc.h"

class NanoAgent;

class GlobalNano : GlobalArc<NanoAgent>
{
public:
	GlobalNano();
	~GlobalNano();

	State<NanoAgent>* CheckTransition(const NanoAgent& agent) const;
};

