#pragma once
#include "State.h"

class NanoAgent;

class IdleNano : public State<NanoAgent>
{
public:
	IdleNano();
	~IdleNano();

	void OnEnter(NanoAgent& agent) const;
	void OnExit(NanoAgent& agent) const;
	void Update(NanoAgent& agent) const;
	int CheckTransition(NanoAgent& agent) const;
};