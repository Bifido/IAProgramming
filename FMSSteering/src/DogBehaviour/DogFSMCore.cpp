#include "DogBehaviour\DogFSMCore.h"
#include "DogBehaviour\StateSwan.h"
#include "DogBehaviour\StateCatchingSheep.h"
#include "DogBehaviour\IdleDog.h"
#include "DogBehaviour\StateFollowSheep.h"
#include "DogBehaviour\GlobalDog.h"

#include <assert.h>
#include <iostream>

using namespace std;

DefaultDogFSMCore::DefaultDogFSMCore()
{
	statesArray[States::IDLE] = new IdleDog();
	statesArray[States::SWAN] = new StateSwan();
	statesArray[States::CATCHING] = new StateCatchingSheep();
	statesArray[States::FOLLOWING_SHEEP] = new StateFollowSheep();

	//NEVER USED. HERE ONLY TO SATISFY DefaultDogFSMCore that inherit from FSMCore.h with pure virtual GetGlobalArc()
	globalArc = new GlobalDog();
}

DefaultDogFSMCore::~DefaultDogFSMCore()
{
	delete dynamic_cast<IdleDog*> (statesArray[States::IDLE]);
	delete dynamic_cast<StateSwan*> (statesArray[States::SWAN]);
	delete dynamic_cast<StateCatchingSheep*> (statesArray[States::CATCHING]);
	delete dynamic_cast<StateFollowSheep*> (statesArray[States::FOLLOWING_SHEEP]);
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