#pragma once
#include "State.h"

class DogAgent;

class StateFollowSheep : public State<DogAgent>
{
public:
	StateFollowSheep();
	~StateFollowSheep();

	void OnEnter(DogAgent& agent) const;
	void OnExit(DogAgent& agent) const;
	void Update(DogAgent& agent, float) const;
	FSMStates CheckTransition(DogAgent& agent) const;
	std::string GetStateName() const;
};