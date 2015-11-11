#include "NanoBehaviour\WatchTvNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include <assert.h>
#include <iostream>

WatchTvNano::WatchTvNano()
{}
WatchTvNano::~WatchTvNano()
{}

void WatchTvNano::OnEnter(NanoAgent& agent) const
{
	agent.SetStaminaRecovering(false);
}

void WatchTvNano::OnExit(NanoAgent& agent) const
{
}

void WatchTvNano::Update(NanoAgent& agent, float dt) const
{
}

FSMStates WatchTvNano::CheckTransition(NanoAgent& agent) const
{
	return SubHomeNanoFSMCore::States::UNLOAD;
}

std::string WatchTvNano::GetStateName() const
{
	return "WatchTvNano";
}