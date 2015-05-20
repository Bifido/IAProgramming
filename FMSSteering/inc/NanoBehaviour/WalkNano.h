#pragma once
#include "State.h"

class NanoAgent;

class WalkNano : public State<NanoAgent>
{
public:
	WalkNano();
	~WalkNano();

	void OnEnter(const NanoAgent* agent);
	void OnExit(const NanoAgent* agent);
	void Update(const NanoAgent* agent);
	State<NanoAgent>* CheckTransition(const NanoAgent* agent) const;
};