#pragma once

template <typename Agent>
class State;

template <typename Agent>
class FSMCore
{
public:
	static FSMCore& GetInstance();
	static State<Agent>* GetDefaultState();
private:
	void Init();
	FSMCore();
	~FSMCore();
};