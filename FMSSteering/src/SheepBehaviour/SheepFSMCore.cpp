#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\IdleSheep.h"
#include "SheepBehaviour\StateBruca.h"
#include "SheepBehaviour\StateEscapingFence.h"
#include "SheepBehaviour\StateEscapingDog.h"
#include "SheepBehaviour\StateBackToFence.h"
#include "SheepBehaviour\GlobalSheep.h"

#include <assert.h>
#include <iostream>

using namespace std;

DefaultSheepFSMCore::DefaultSheepFSMCore()
{
	statesArray[States::IDLE] = new IdleSheep();
	statesArray[States::BRUCA] = new StateBruca();
	statesArray[States::ESCAPING_FENCE] = new StateEscapingFence();
	statesArray[States::ESCAPE_FROM_DOG] = new StateEscapingDog();
	statesArray[States::BACK_IN_FENCE] = new StateBackToFence();

	//NEVER USED. HERE ONLY TO SATISFY DefaultSheepFSMCore that inherit from FSMCore.h with pure virtual GetGlobalArc()
	globalArc = new GlobalSheep();
}

DefaultSheepFSMCore::~DefaultSheepFSMCore()
{
	delete dynamic_cast<IdleSheep*>(statesArray[States::IDLE]);
	delete dynamic_cast<StateBruca*>(statesArray[States::BRUCA]);
	delete dynamic_cast<StateEscapingFence*>(statesArray[States::ESCAPING_FENCE]);
	delete dynamic_cast<StateEscapingDog*>(statesArray[States::ESCAPE_FROM_DOG]);
	delete dynamic_cast<StateBackToFence*>(statesArray[States::BACK_IN_FENCE]);
}

FSMCore<SheepAgent>* DefaultSheepFSMCore::GetInstance()
{
	static DefaultSheepFSMCore m_instance;
	return &m_instance;
}

State<SheepAgent>* DefaultSheepFSMCore::GetDefaultState() const
{
	return statesArray[States::IDLE];
}

State<SheepAgent>* DefaultSheepFSMCore::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<SheepAgent>* DefaultSheepFSMCore::GetGlobalArc() const
{
	return globalArc;
}

bool DefaultSheepFSMCore::IsStateValid(FSMStates stateId) const
{
	return (stateId != States::NOT_VALID);
}

FSMStates DefaultSheepFSMCore::GetNotValidState() const
{
	return States::NOT_VALID;
}