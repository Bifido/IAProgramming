#pragma once
#include "State.h"

class NanoAgent;

class RestoreNano : public State<NanoAgent>
{
public:
	RestoreNano();
	~RestoreNano();

	void OnEnter(NanoAgent& agent) const;
	void OnExit(NanoAgent& agent) const;
	void Update(NanoAgent& agent, float dt) const;
	FSMStates CheckTransition(NanoAgent& agent) const;
	std::string GetStateName() const;
};