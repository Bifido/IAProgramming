#pragma once
#include "GlobalArc.h"
#include "SheepBehaviour\SheepFSMCore.h"

class SheepAgent;

class GlobalSheep : public GlobalArc<SheepAgent>
{
public:
	GlobalSheep(){};
	~GlobalSheep(){};

	FSMStates CheckTransition(SheepAgent& agent) const {
		return DefaultSheepFSMCore::States::BRUCA;
	}
};

