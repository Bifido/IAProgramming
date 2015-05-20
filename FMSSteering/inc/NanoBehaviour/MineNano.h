#pragma once
#include "State.h"

class NanoAgent;

class MineNano : public State<NanoAgent>
{
public:
	MineNano();
	~MineNano();

	void OnEnter(const NanoAgent* agent);
	void OnExit(const NanoAgent* agent);
	void Update(const NanoAgent* agent);
	State<NanoAgent>* CheckTransition(const NanoAgent* agent) const;
};