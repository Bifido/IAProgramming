#pragma once
#include "FSMCore.h"
//#include "GlobalNano.h"

class NanoAgent;

template <typename Agent>
class GlobalArc;


class DefaultNanoFSMCore : FSMCore < NanoAgent >
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

	static FSMCore<NanoAgent>* GetInstance();
	State<NanoAgent>* GetDefaultState() const;
	State<NanoAgent>* GetState(FSMStates stateId) const;
	GlobalArc<NanoAgent>* GetGlobalArc() const;

	bool IsStateValid(FSMStates stateId) const;
	FSMStates GetNotValidState() const;
private:
	DefaultNanoFSMCore();
	~DefaultNanoFSMCore();

	State<NanoAgent>* statesArray[COUNT];
	GlobalArc<NanoAgent>* globalArc;
};

class SubWalkNanoFSMCore : FSMCore < NanoAgent>
{

public:
	enum States{
		NOT_VALID = -1,
		LEFT = 0,
		RIGHT = 1,
		COUNT
	};

	static FSMCore<NanoAgent>* GetInstance();
	State<NanoAgent>* GetDefaultState() const;
	State<NanoAgent>* GetState(FSMStates stateId) const;
	GlobalArc<NanoAgent>* GetGlobalArc() const;

	bool IsStateValid(FSMStates stateId) const;
	FSMStates GetNotValidState() const;
private:
	SubWalkNanoFSMCore();
	~SubWalkNanoFSMCore();

	State<NanoAgent>* statesArray[COUNT];
	GlobalArc<NanoAgent>* globalArc;
};