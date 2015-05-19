#include "NanoBehaviour\NanoFSMCore.h"

FSMCore<NanoAgent>::FSMCore()
{
	statesArray[IDLE] = new IdleNano();
	statesArray[WALK] = new WalkNano();
	statesArray[MINE] = new MineNano();
	statesArray[HOME] = new HomeNano();

}

FSMCore<NanoAgent>::~FSMCore()
{

}

FSMCore<NanoAgent>& FSMCore<NanoAgent>::GetInstance()
{
	static FSMCore m_instance;
	return m_instance;
}

State<NanoAgent>* FSMCore<NanoAgent>::GetDefaultState()
{
	return statesArray[IDLE];
}