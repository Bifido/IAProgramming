#include "NanoBehaviour\UnloadStonesNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include <assert.h>
#include <iostream>

UnloadStonesNano::UnloadStonesNano()
{}
UnloadStonesNano::~UnloadStonesNano()
{}

void UnloadStonesNano::OnEnter(NanoAgent& agent) const
{
}

void UnloadStonesNano::OnExit(NanoAgent& agent) const
{
}

void UnloadStonesNano::Update(NanoAgent& agent, float dt) const
{
	if (agent.GetCarriedStonesNumber() > 0)
		agent.DecrementStoneCarried(agent.STONES_RATIO);
}

FSMStates UnloadStonesNano::CheckTransition(NanoAgent& agent) const
{
	if (agent.GetCarriedStonesNumber() <= 0)
	{
		return SubHomeNanoFSMCore::States::RESTORE;
	}
	return SubHomeNanoFSMCore::States::UNLOAD;
}

std::string UnloadStonesNano::GetStateName() const
{
	return "UnloadStonesNano";
}