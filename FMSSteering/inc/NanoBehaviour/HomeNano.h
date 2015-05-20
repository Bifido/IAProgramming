#pragma once
#include "State.h"

class NanoAgent;

class HomeNano : public State<NanoAgent>
{
public:
	HomeNano();
	~HomeNano();

	void OnEnter(NanoAgent*);
	void OnExit(NanoAgent*);
	void Update(NanoAgent*);
	State<NanoAgent>* CheckTransition();
};