#pragma once
#include "State.h"

class NanoAgent;

class IdleNano : public State<NanoAgent>
{
public:
	IdleNano();
	~IdleNano();

	void OnEnter(NanoAgent*);
	void OnExit(NanoAgent*);
	void Update(NanoAgent*);
	State<NanoAgent>* CheckTransition();
};