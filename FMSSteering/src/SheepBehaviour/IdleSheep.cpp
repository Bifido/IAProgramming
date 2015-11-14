#include "SheepBehaviour\IdleSheep.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Mine.h"

#include <assert.h>

IdleSheep::IdleSheep()
{}
IdleSheep::~IdleSheep()
{}

void IdleSheep::OnEnter(SheepAgent& agent) const
{}
void IdleSheep::OnExit(SheepAgent& agent) const
{}
void IdleSheep::Update(SheepAgent& agent, float dt) const
{}

FSMStates IdleSheep::CheckTransition(SheepAgent& agent) const
{
	return DefaultSheepFSMCore::States::BRUCA;
}

std::string IdleSheep::GetStateName() const
{
	return "IdleNano";
}