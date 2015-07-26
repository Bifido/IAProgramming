#pragma once
#include "FSMCore.h"

// TODO review everything

class SheepAgent;
template <typename Agent> class GlobalArc;


class DefaultSheepFSMCore : FSMCore < SheepAgent >
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