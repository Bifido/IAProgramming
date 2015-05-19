#pragma once
#include "State.h"

class NanoAgent;

class MineNano : public State<NanoAgent>
{
public:
	MineNano();
	~MineNano();

	void OnEnter(NanoAgent*);
	void OnExit(NanoAgent*);
	void Update(NanoAgent*);
	State<NanoAgent>* CheckTransition();
};