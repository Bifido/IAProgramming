#pragma once

template <typename Agent>
class State;

template <typename Agent>
class FSMCore
{
public:
	enum States{};

	static FSMCore& GetInstance();
	State<Agent>* GetDefaultState() const;
	State<Agent>* GetState(States stateId) const;
private:
	FSMCore();
	~FSMCore();
};