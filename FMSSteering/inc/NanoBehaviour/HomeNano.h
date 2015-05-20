#pragma once
#include "State.h"

class NanoAgent;

class HomeNano : public State<NanoAgent>
{
public:
	HomeNano();
	~HomeNano();

	void OnEnter(const NanoAgent* agent);
	void OnExit(const NanoAgent* agent);
	void Update(const NanoAgent* agent);
	State<NanoAgent>* CheckTransition(const NanoAgent* agent) const;
};