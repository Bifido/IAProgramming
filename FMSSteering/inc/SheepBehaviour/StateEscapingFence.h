#pragma once
#include "State.h"
#include "SFML\System\Vector2.hpp"

class SheepAgent;

class StateEscapingFence : public State<SheepAgent>
{
public:
	StateEscapingFence();
	~StateEscapingFence();

	void OnEnter(SheepAgent& agent) const;
	void OnExit(SheepAgent& agent) const;
	void Update(SheepAgent& agent) const;
	FSMStates CheckTransition(SheepAgent& agent) const;
};