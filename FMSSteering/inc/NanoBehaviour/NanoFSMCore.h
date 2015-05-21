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
	enum States{
		NOT_VALID = -1,
		IDLE = 0,
		WALK = 1,
		MINE = 2,
		HOME = 3,
		COUNT
	};

	static FSMCore& GetInstance();
	State<NanoAgent>* GetDefaultState() const;
	State<NanoAgent>* GetState(States stateId) const;
private:
	FSMCore();
	~FSMCore();

	State<NanoAgent>* statesArray[COUNT];
};
