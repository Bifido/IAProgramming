#pragma once

typedef int FSMStates;

template <typename Agent>
class State;
template <typename Agent>
class GlobalArc;

template <typename Agent>
class FSMCore
{
public:
	//static FSMCore& GetInstance(){};
	virtual State<Agent>* GetDefaultState() const = 0;
	virtual State<Agent>* GetState(FSMStates stateId) const = 0;
	virtual bool IsStateValid(FSMStates stateId) const = 0;
	virtual FSMStates GetNotValidState() const = 0;
	virtual GlobalArc<Agent>* GetGlobalArc() const = 0;
protected:
	FSMCore(){};
	virtual ~FSMCore(){};
};