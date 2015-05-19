#pragma once
#include "State.h"

class NanoAgent;

class WalkNano : public State<NanoAgent>
{
public:
	WalkNano();
	~WalkNano();

	void OnEnter(NanoAgent*);
	void OnExit(NanoAgent*);
	void Update(NanoAgent*);
	State<NanoAgent>* CheckTransition();
};