#pragma once
#include "FSMCore.h"
#include "WalkNano.h"
#include "IdleNano.h"
#include "MineNano.h"
#include "HomeNano.h"

class NanoAgent;

template<>
class FSMCore < NanoAgent >
{

public:
	enum {
		IDLE = 0,
		WALK = 1,
		MINE = 2,
		HOME = 3,
		COUNT
	};

	static FSMCore& GetInstance();
	State<NanoAgent>* GetDefaultState();
private:
	FSMCore();
	~FSMCore();

	State<NanoAgent>* statesArray[COUNT];
};

//FSMCore<NanoAgent>::FSMCore()
//{
//	statesArray[IDLE] = new IdleNano();
//	statesArray[WALK] = new WalkNano();
//	statesArray[MINE] = new MineNano();
//	statesArray[HOME] = new HomeNano();
//
//}
//
//FSMCore<NanoAgent>::~FSMCore()
//{
//
//}
//
//FSMCore<NanoAgent>& FSMCore<NanoAgent>::GetInstance()
//{
//	static FSMCore m_instance;
//	return m_instance;
//}
//
//State<NanoAgent>* FSMCore<NanoAgent>::GetDefaultState()
//{
//	return statesArray[IDLE];
//}
