#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\GlobalNano.h"
#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\IdleNano.h"
#include "NanoBehaviour\MineNano.h"
#include "NanoBehaviour\HomeNano.h"
#include "NanoBehaviour\WalkNanoLeft.h"
#include "NanoBehaviour\WalkNanoRight.h"
#include <assert.h>

DefaultNanoFSMCore::DefaultNanoFSMCore()
{
	statesArray[States::IDLE] = new IdleNano();
	statesArray[States::WALK] = new WalkNano();
	statesArray[States::MINE] = new MineNano();
	statesArray[States::HOME] = new HomeNano();

	globalArc = new GlobalNano();
}

DefaultNanoFSMCore::~DefaultNanoFSMCore()
{

}

FSMCore<NanoAgent>* DefaultNanoFSMCore::GetInstance()
{
	static DefaultNanoFSMCore m_instance;
	return &m_instance;
}

State<NanoAgent>* DefaultNanoFSMCore::GetDefaultState() const
{
	return statesArray[States::IDLE];
}

State<NanoAgent>* DefaultNanoFSMCore::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<NanoAgent>* DefaultNanoFSMCore::GetGlobalArc() const
{
	return globalArc;
}

bool DefaultNanoFSMCore::IsStateValid(FSMStates stateId) const
{
	return (stateId != States::NOT_VALID);
}

FSMStates DefaultNanoFSMCore::GetNotValidState() const
{
	return States::NOT_VALID;
}



SubWalkNanoFSMCore::SubWalkNanoFSMCore()
{
	statesArray[States::LEFT] = new WalkNanoLeft();
	statesArray[States::RIGHT] = new WalkNanoRight();
}

SubWalkNanoFSMCore::~SubWalkNanoFSMCore()
{

}

FSMCore<NanoAgent>* SubWalkNanoFSMCore::GetInstance()
{
	static SubWalkNanoFSMCore m_instance;
	return &m_instance;
}

State<NanoAgent>* SubWalkNanoFSMCore::GetDefaultState() const
{
	return statesArray[States::LEFT];
}

State<NanoAgent>* SubWalkNanoFSMCore::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<NanoAgent>* SubWalkNanoFSMCore::GetGlobalArc() const
{
	return globalArc;
}

bool SubWalkNanoFSMCore::IsStateValid(FSMStates stateId) const
{
	return (stateId != States::NOT_VALID);
}

FSMStates SubWalkNanoFSMCore::GetNotValidState() const
{
	return States::NOT_VALID;
}