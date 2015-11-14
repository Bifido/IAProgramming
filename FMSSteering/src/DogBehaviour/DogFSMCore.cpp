#include "DogBehaviour\DogFSMCore.h"
#include "DogBehaviour\StateSwan.h"
#include "DogBehaviour\StateCatchingSheep.h"
#include "DogBehaviour\IdleDog.h"
//#include "SheepBehaviour\StateBackToFence.h"
#include "DogBehaviour\GlobalDog.h"

#include <assert.h>
#include <iostream>

using namespace std;

DefaultDogFSMCore::DefaultDogFSMCore()
{
	statesArray[States::IDLE] = new IdleDog();
	statesArray[States::SWAN] = new StateSwan();
	statesArray[States::CATCHING] = new StateCatchingSheep();

	//NEVER USED. HERE ONLY TO SATISFY DefaultDogFSMCore that inherit from FSMCore.h with pure virtual GetGlobalArc()
	globalArc = new GlobalDog();
}

DefaultDogFSMCore::~DefaultDogFSMCore()
{
}

FSMCore<DogAgent>* DefaultDogFSMCore::GetInstance()
{
	static DefaultDogFSMCore m_instance;
	return &m_instance;
}

State<DogAgent>* DefaultDogFSMCore::GetDefaultState() const
{
	return statesArray[States::IDLE];
}

State<DogAgent>* DefaultDogFSMCore::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<DogAgent>* DefaultDogFSMCore::GetGlobalArc() const
{
	return globalArc;
}

bool DefaultDogFSMCore::IsStateValid(FSMStates stateId) const
{
	return (stateId != States::NOT_VALID);
}

FSMStates DefaultDogFSMCore::GetNotValidState() const
{
	return States::NOT_VALID;
}