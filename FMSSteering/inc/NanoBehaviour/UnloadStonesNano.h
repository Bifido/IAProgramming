#pragma once
#include "State.h"

class NanoAgent;

class UnloadStonesNano : public State<NanoAgent>
{
public:
	UnloadStonesNano();
	~UnloadStonesNano();

	void OnEnter(NanoAgent& agent) const;
	void OnExit(NanoAgent& agent) const;
	void Update(NanoAgent& agent, float dt) const;
	FSMStates CheckTransition(NanoAgent& agent) const;
	std::string GetStateName() const;
};