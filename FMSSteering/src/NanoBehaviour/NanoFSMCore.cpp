#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\GlobalNano.h"
#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\IdleNano.h"
#include "NanoBehaviour\MineNano.h"
#include "NanoBehaviour\HomeNano.h"
#include "NanoBehaviour\UnloadStonesNano.h"
#include "NanoBehaviour\RestoreNano.h"
#include "NanoBehaviour\WatchTvNano.h"
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
	delete dynamic_cast<IdleNano*>(statesArray[States::IDLE]);
	delete dynamic_cast<WalkNano*>(statesArray[States::WALK]);
	delete dynamic_cast<MineNano*>(statesArray[States::MINE]);
	delete dynamic_cast<HomeNano*>(statesArray[States::HOME]);
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



SubHomeNanoFSMCore::SubHomeNanoFSMCore()
{
	statesArray[States::UNLOAD] = new UnloadStonesNano();
	statesArray[States::RESTORE] = new RestoreNano();
	statesArray[States::WATCH_TV] = new WatchTvNano();
}

SubHomeNanoFSMCore::~SubHomeNanoFSMCore()
{
	delete dynamic_cast<UnloadStonesNano*>(statesArray[States::UNLOAD]);
	delete dynamic_cast<RestoreNano*>(statesArray[States::RESTORE]);
	delete dynamic_cast<WatchTvNano*>(statesArray[States::WATCH_TV]);
}

FSMCore<NanoAgent>* SubHomeNanoFSMCore::GetInstance()
{
	static SubHomeNanoFSMCore m_instance;
	return &m_instance;
}

State<NanoAgent>* SubHomeNanoFSMCore::GetDefaultState() const
{
	return statesArray[States::UNLOAD];
}

State<NanoAgent>* SubHomeNanoFSMCore::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<NanoAgent>* SubHomeNanoFSMCore::GetGlobalArc() const
{
	return globalArc;
}

bool SubHomeNanoFSMCore::IsStateValid(FSMStates stateId) const
{
	return (stateId != States::NOT_VALID);
}

FSMStates SubHomeNanoFSMCore::GetNotValidState() const
{
	return States::NOT_VALID;
}