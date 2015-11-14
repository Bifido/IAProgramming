#pragma once
#include "State.h"

class DogAgent;

class IdleDog : public State<DogAgent>
{
public:
	IdleDog();
	~IdleDog();

	void OnEnter(DogAgent& agent) const;
	void OnExit(DogAgent& agent) const;
	void Update(DogAgent& agent, float dt) const;
	FSMStates CheckTransition(DogAgent& agent) const;
	std::string GetStateName() const;
};