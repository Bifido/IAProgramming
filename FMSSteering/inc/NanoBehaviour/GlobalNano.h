#pragma once
#include "GlobalArc.h"

class NanoAgent;

class GlobalNano : GlobalArc<NanoAgent>
{
public:
	GlobalNano();
	~GlobalNano();

	int CheckTransition(NanoAgent& agent) const;
};

