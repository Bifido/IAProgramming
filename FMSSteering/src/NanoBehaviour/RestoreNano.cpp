#include "NanoBehaviour\RestoreNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include <assert.h>
#include <iostream>


RestoreNano::RestoreNano()
{}
RestoreNano::~RestoreNano()
{}

void RestoreNano::OnEnter(NanoAgent& agent) const{
}

void RestoreNano::OnExit(NanoAgent& agent) const{
}

void RestoreNano::Update(NanoAgent& agent, float dt) const
{
	agent.IncrementStamina(agent.GetHome()->GetStaminaRecovered() * agent.STAMINA_RECOVER);
}

FSMStates RestoreNano::CheckTransition(NanoAgent& agent) const
{
	if (agent.GetStamina() >= agent.MAX_STAMINA)
	{
		return SubHomeNanoFSMCore::States::WATCH_TV;
	}

	return SubHomeNanoFSMCore::States::RESTORE;
}

std::string RestoreNano::GetStateName() const
{
	return "RestoreNano";
}