#pragma once
#include "FSMCore.h"

class SheepAgent;

template <typename Agent>
class GlobalArc;

class DefaultSheepFSMCore : FSMCore < SheepAgent >
{

public: 
	enum States{
		NOT_VALID = -1,
		ESCAPE_FROM_FENCE = 0,
		ESCAPE_FROM_DOG = 1,
		BACK_IN_FENCE = 2,
		WALK = 3,
		COUNT
	};

	static FSMCore<SheepAgent>* GetInstance();
	State<SheepAgent>* GetDefaultState() const;
	State<SheepAgent>* GetState(FSMStates stateId) const;
	GlobalArc<SheepAgent>* GetGlobalArc() const;

	bool IsStateValid(FSMStates stateId) const;
	FSMStates GetNotValidState() const;
private:
	DefaultSheepFSMCore();
	~DefaultSheepFSMCore();

	State<SheepAgent>* statesArray[COUNT];
	GlobalArc<SheepAgent>* globalArc;
};