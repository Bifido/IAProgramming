#pragma once
#include "State.h"
#include "SFML\System\Vector2.hpp"

class SheepAgent;

class StateBackToFence : public State<SheepAgent>
{
public:
	StateBackToFence();
	~StateBackToFence();

	void OnEnter(SheepAgent& agent) const;
	void OnExit(SheepAgent& agent) const;
	void Update(SheepAgent& agent, float dt) const;
	FSMStates CheckTransition(SheepAgent& agent) const;
	std::string GetStateName() const;
};