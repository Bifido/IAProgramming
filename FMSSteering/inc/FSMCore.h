#pragma once

template <typename Agent>
class State;

template <typename Agent>
class FSMCore
{
public:
	static FSMCore& GetInstance() = 0;
	State<Agent>* GetDefaultState() const = 0;
	State<Agent>* GetState(unsigned int stateId) const = 0;
private:
	FSMCore();
	~FSMCore();
};