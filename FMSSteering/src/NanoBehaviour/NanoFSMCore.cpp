#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\GlobalNano.h"
#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\IdleNano.h"
#include "NanoBehaviour\MineNano.h"
#include "NanoBehaviour\HomeNano.h"
#include "NanoBehaviour\WalkNanoLeft.h"
#include "NanoBehaviour\WalkNanoRight.h"
#include <assert.h>

FSMCore<NanoAgent,0>::FSMCore()
{
	statesArray[States::IDLE] = new IdleNano();
	statesArray[States::WALK] = new WalkNano();
	statesArray[States::MINE] = new MineNano();
	statesArray[States::HOME] = new HomeNano();

	globalArc = new GlobalNano();
}

FSMCore<NanoAgent,0>::~FSMCore()
{

}

FSMCore<NanoAgent,0>& FSMCore<NanoAgent,0>::GetInstance()
{
	static FSMCore m_instance;
	return m_instance;
}

State<NanoAgent>* FSMCore<NanoAgent,0>::GetDefaultState() const
{
	return statesArray[States::IDLE];
}

State<NanoAgent>* FSMCore<NanoAgent,0>::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<NanoAgent>* FSMCore<NanoAgent, 0>::GetGlobalArc() const
{
	return globalArc;
}

bool FSMCore<NanoAgent, 0>::IsStateValid(FSMStates stateId)
{
	return (stateId != States::NOT_VALID);
}

FSMStates FSMCore<NanoAgent, 0>::GetNotValidState()
{
	return States::NOT_VALID;
}



FSMCore<NanoAgent, 1>::FSMCore()
{
	statesArray[States::IDLE] = new IdleNano();
	statesArray[States::LEFT] = new WalkNanoLeft();
	statesArray[States::RIGHT] = new WalkNanoRight();

	globalArc = new GlobalNano();
}

FSMCore<NanoAgent, 1>::~FSMCore()
{

}

FSMCore<NanoAgent, 1>& FSMCore<NanoAgent, 1>::GetInstance()
{
	static FSMCore m_instance;
	return m_instance;
}

State<NanoAgent>* FSMCore<NanoAgent, 1>::GetDefaultState() const
{
	return statesArray[States::IDLE];
}

State<NanoAgent>* FSMCore<NanoAgent, 1>::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<NanoAgent>* FSMCore<NanoAgent, 1>::GetGlobalArc() const
{
	return globalArc;
}

bool FSMCore<NanoAgent, 1>::IsStateValid(FSMStates stateId)
{
	return (stateId != States::NOT_VALID);
}

FSMStates FSMCore<NanoAgent, 1>::GetNotValidState()
{
	return States::NOT_VALID;
}