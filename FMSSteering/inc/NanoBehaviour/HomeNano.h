#pragma once
#include "State.h"

class NanoAgent;

class HomeNano : public State<NanoAgent>
{
public:
	HomeNano();
	~HomeNano();

	void OnEnter(NanoAgent& agent) const;
	void OnExit(NanoAgent& agent) const;
	void Update(NanoAgent& agent) const;
	FSMStates CheckTransition(NanoAgent& agent) const;
};