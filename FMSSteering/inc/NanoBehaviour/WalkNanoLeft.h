#pragma once
#include "State.h"

class NanoAgent;

class WalkNanoLeft : public State<NanoAgent>
{
public:
	WalkNanoLeft();
	~WalkNanoLeft();

	void OnEnter(NanoAgent& agent) const;
	void OnExit(NanoAgent& agent) const;
	void Update(NanoAgent& agent) const;
	FSMStates CheckTransition(NanoAgent& agent) const;
};