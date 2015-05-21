#include "NanoBehaviour\NanoFSMCore.h"
#include <assert.h>

FSMCore<NanoAgent>::FSMCore()
{
	statesArray[States::IDLE] = new IdleNano();
	statesArray[States::WALK] = new WalkNano();
	statesArray[States::MINE] = new MineNano();
	statesArray[States::HOME] = new HomeNano();

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

State<NanoAgent>* FSMCore<NanoAgent>::GetState(FSMCore<NanoAgent>::States stateId) const
{
	assert(stateId < States::COUNT);

	return statesArray[stateId];
}