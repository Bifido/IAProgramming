#pragma once
#include "FSMCore.h"

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

class SubHomeNanoFSMCore : FSMCore < NanoAgent>
{

public:
	enum States{
		NOT_VALID = -1,
		UNLOAD = 0,
		RESTORE = 1,
		WATCH_TV = 2,
		COUNT
	};

	static FSMCore<NanoAgent>* GetInstance();
	State<NanoAgent>* GetDefaultState() const;
	State<NanoAgent>* GetState(FSMStates stateId) const;
	GlobalArc<NanoAgent>* GetGlobalArc() const;

	bool IsStateValid(FSMStates stateId) const;
	FSMStates GetNotValidState() const;
private:
	SubHomeNanoFSMCore();
	~SubHomeNanoFSMCore();

	State<NanoAgent>* statesArray[COUNT];
	GlobalArc<NanoAgent>* globalArc;
};