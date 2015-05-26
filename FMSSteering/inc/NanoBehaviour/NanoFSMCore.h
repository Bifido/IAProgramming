#pragma once
#include "FSMCore.h"
//#include "GlobalNano.h"

class NanoAgent;

template <typename Agent>
class GlobalArc;

template<>
class FSMCore < NanoAgent , 0>
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

template<>
class FSMCore < NanoAgent, 1>
{

public:
	enum States{
		NOT_VALID = -1,
		IDLE = 0,
		LEFT = 1,
		RIGHT = 2,
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