#pragma once
#include "State.h"

class SheepAgent;

class WalkSheep : public State<SheepAgent>
{
public:
	WalkSheep();
	~WalkSheep();

	void OnEnter(SheepAgent& agent) const;
	void OnExit(SheepAgent& agent) const;
	void Update(SheepAgent& agent) const;
	FSMStates CheckTransition(SheepAgent& agent) const;
};