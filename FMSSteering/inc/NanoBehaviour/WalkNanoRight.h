#pragma once
#include "State.h"

class NanoAgent;

class WalkNanoRight : public State<NanoAgent>
{
public:
	WalkNanoRight();
	~WalkNanoRight();

	void OnEnter(NanoAgent& agent) const;
	void OnExit(NanoAgent& agent) const;
	void Update(NanoAgent& agent) const;
	FSMStates CheckTransition(NanoAgent& agent) const;
};