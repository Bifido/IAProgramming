#pragma once
#include "State.h"

class NanoAgent;

class IdleNano : public State<NanoAgent>
{
public:
	IdleNano();
	~IdleNano();

	void OnEnter(const NanoAgent* agent);
	void OnExit(const NanoAgent* agent);
	void Update(const NanoAgent* agent);
	State<NanoAgent>* CheckTransition(const NanoAgent* agent) const;
};