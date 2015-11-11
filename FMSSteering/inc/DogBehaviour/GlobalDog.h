#pragma once
#include "GlobalArc.h"
#include "DogBehaviour\DogFSMCore.h"

class DogAgent;

class GlobalDog : public GlobalArc<DogAgent>
{
public:
	GlobalDog(){};
	~GlobalDog(){};

	FSMStates CheckTransition(DogAgent& agent) const {
		return DefaultDogFSMCore::States::NOT_VALID;
	}
};

