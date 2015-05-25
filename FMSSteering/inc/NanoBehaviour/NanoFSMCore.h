#pragma once
#include "FSMCore.h"
#include "GlobalNano.h"
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
	State<NanoAgent>* GetState(FSMStates stateId) const;
	GlobalArc<NanoAgent>* GetGlobalArc() const;

	static bool IsStateValid(FSMStates stateId);
	static FSMStates GetNotValidState();
private:
	FSMCore();
	~FSMCore();

	State<NanoAgent>* statesArray[COUNT];
	GlobalArc<NanoAgent>* globalArc;
};
