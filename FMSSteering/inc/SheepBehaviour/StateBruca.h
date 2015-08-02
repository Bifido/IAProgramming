#pragma once
#include "State.h"

class SheepAgent;

class StateBruca : public State<SheepAgent>
{
public:
	StateBruca();
	~StateBruca();

	void OnEnter(SheepAgent& agent) const;
	void OnExit(SheepAgent& agent) const;
	void Update(SheepAgent& agent) const;
	FSMStates CheckTransition(SheepAgent& agent) const;
};