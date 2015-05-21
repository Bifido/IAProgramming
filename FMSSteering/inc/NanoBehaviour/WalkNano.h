#pragma once
#include "State.h"

class NanoAgent;

class WalkNano : public State<NanoAgent>
{
public:
	WalkNano();
	~WalkNano();

	void OnEnter(NanoAgent& agent) const;
	void OnExit(NanoAgent& agent) const;
	void Update(NanoAgent& agent) const;
	State<NanoAgent>* CheckTransition(NanoAgent& agent) const;
};