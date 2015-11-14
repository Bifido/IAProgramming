#include "DogBehaviour\IdleDog.h"
#include "DogBehaviour\DogFSMCore.h"
#include "DogBehaviour\DogAgent.h"

#include "PassiveObj\Mine.h"

#include <assert.h>

IdleDog::IdleDog()
{}
IdleDog::~IdleDog()
{}

void IdleDog::OnEnter(DogAgent& agent) const
{}
void IdleDog::OnExit(DogAgent& agent) const
{}
void IdleDog::Update(DogAgent& agent, float dt) const
{}

FSMStates IdleDog::CheckTransition(DogAgent& agent) const
{
	return DefaultDogFSMCore::States::SWAN;
}

std::string IdleDog::GetStateName() const
{
	return "IdleNano";
}