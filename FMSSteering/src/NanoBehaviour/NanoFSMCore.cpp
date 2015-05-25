#include "NanoBehaviour\NanoFSMCore.h"
#include <assert.h>

FSMCore<NanoAgent>::FSMCore()
{
	statesArray[States::IDLE] = new IdleNano();
	statesArray[States::WALK] = new WalkNano();
	statesArray[States::MINE] = new MineNano();
	statesArray[States::HOME] = new HomeNano();

	globalArc = new GlobalNano();
}

FSMCore<NanoAgent>::~FSMCore()
{

}

FSMCore<NanoAgent>& FSMCore<NanoAgent>::GetInstance()
{
	static FSMCore m_instance;
	return m_instance;
}

State<NanoAgent>* FSMCore<NanoAgent>::GetDefaultState() const
{
	return statesArray[States::IDLE];
}

State<NanoAgent>* FSMCore<NanoAgent>::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<NanoAgent>* FSMCore<NanoAgent>::GetGlobalArc() const
{
	return globalArc;
}

bool FSMCore<NanoAgent>::IsStateValid(FSMStates stateId)
{
	return (stateId != States::NOT_VALID);
}

FSMStates FSMCore<NanoAgent>::GetNotValidState()
{
	return States::NOT_VALID;
}