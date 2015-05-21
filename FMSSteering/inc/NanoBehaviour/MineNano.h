#pragma once
#include "State.h"

class NanoAgent;

class MineNano : public State<NanoAgent>
{
public:
	MineNano();
	~MineNano();

	void OnEnter(NanoAgent& agent) const;
	void OnExit(NanoAgent& agent) const;
	void Update(NanoAgent& agent) const;
	int CheckTransition(NanoAgent& agent) const;
};