#pragma once
#include "FSMCore.h"

class DogAgent;

template <typename Agent>
class GlobalArc;

class DefaultDogFSMCore : FSMCore < DogAgent >
{

public:
	enum States{
		NOT_VALID = -1,
		IDLE = 0,
		SWAN = 1,			//gironzolare
		CATCHING = 2,
		COUNT
	};

	static FSMCore<DogAgent>* GetInstance();
	State<DogAgent>* GetDefaultState() const;
	State<DogAgent>* GetState(FSMStates stateId) const;
	GlobalArc<DogAgent>* GetGlobalArc() const;

	bool IsStateValid(FSMStates stateId) const;
	FSMStates GetNotValidState() const;
private:
	DefaultDogFSMCore();
	~DefaultDogFSMCore();

	State<DogAgent>* statesArray[COUNT];
	GlobalArc<DogAgent>* globalArc;
};