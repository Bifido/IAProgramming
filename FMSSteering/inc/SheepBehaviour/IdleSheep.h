#pragma once
#include "State.h"

class SheepAgent;

class IdleSheep : public State<SheepAgent>
{
public:
	IdleSheep();
	~IdleSheep();

	void OnEnter(SheepAgent& agent) const;
	void OnExit(SheepAgent& agent) const;
	void Update(SheepAgent& agent, float dt) const;
	FSMStates CheckTransition(SheepAgent& agent) const;
	std::string GetStateName() const;
};