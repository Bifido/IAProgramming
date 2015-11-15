#include "NanoBehaviour\IdleNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"

#include <assert.h>

IdleNano::IdleNano()
{}
IdleNano::~IdleNano()
{}

void IdleNano::OnEnter(NanoAgent& agent) const
{}
void IdleNano::OnExit(NanoAgent& agent) const
{}
void IdleNano::Update(NanoAgent& agent, float dt) const
{
}

FSMStates IdleNano::CheckTransition(NanoAgent& agent) const
{
	// if exist a mine for this dwarf and has at least 1 stone, WALK TO MINE!
	if (agent.GetMine() != nullptr && agent.GetMine()->GetActualStonesNumber() > 0){
		// Setting the mine position as new target
		agent.SetTarget(agent.GetMine()->GetPosition());
		// go to state: WALK
		return DefaultNanoFSMCore::States::WALK;
	}
	return DefaultNanoFSMCore::States::IDLE;
}

std::string IdleNano::GetStateName() const
{
	return "IdleNano";
}