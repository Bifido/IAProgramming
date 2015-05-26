#pragma once

typedef int FSMStates;

template <typename Agent>
class State;

template <int I>
struct intToType
{
	enum
	{
		value = I
	};
};

//void SwitchCamera(intToType<5>);

//SwitchCamera(5);

template <typename Agent, int I>
class FSMCore
{
public:

	static FSMCore& GetInstance() = delete;
	State<Agent>* GetDefaultState() const = delete;
	State<Agent>* GetState(FSMStates stateId) const = delete;
	static bool IsStateValid(FSMStates stateId) = delete;
	static FSMStates GetNotValidState() = delete;
private:
	FSMCore() = delete;
	~FSMCore() = delete;
};