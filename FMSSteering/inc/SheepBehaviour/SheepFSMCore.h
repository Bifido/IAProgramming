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
		BRUCA = 0,
		ESCAPING_FENCE = 1,
		/*ESCAPING_DOG = 1,
		BACK_IN_FENCE = 3,*/
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