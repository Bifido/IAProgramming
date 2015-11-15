#include "NanoBehaviour\MineNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"
#include "PassiveObj\Home.h"
#include "PassiveObj\Mine.h"
#include "ViewComponent.h"

#include <iostream>

MineNano::MineNano()
{}
MineNano::~MineNano()
{}

void MineNano::OnEnter(NanoAgent& agent) const
{
	if (agent.GetViewComponent() != nullptr)
	{
		agent.GetViewComponent()->SetDrawable(false);
	}

	std::cout << "Mine stones " << agent.GetMine()->GetActualStonesNumber() << std::endl;
}
void MineNano::OnExit(NanoAgent& agent) const
{
	if (agent.GetViewComponent() != nullptr)
	{
		agent.GetViewComponent()->SetDrawable(true);
	}
}
void MineNano::Update(NanoAgent& agent, float dt) const
{
	agent.DecrementStamina(agent.STAMINA_USAGE);
	if (agent.GetMine()->GetActualStonesNumber() > 0)
	{
		agent.IncrementStoneCarried(agent.STONES_RATIO);
		agent.GetMine()->DecrementStonesNumber(agent.STONES_RATIO);
	}
}

FSMStates MineNano::CheckTransition(NanoAgent& agent) const
{
	// if exist a home for this dwarf and he is full of stones, WALK TO HOME!
	if (agent.GetHome() != nullptr && (agent.HasReachedMaxStone() || agent.GetMine()->GetActualStonesNumber() <= 0))
	{
		// Setting the mine position as new target
		agent.SetTarget(agent.GetHome()->GetPosition());
		// go to state: WALK
		return DefaultNanoFSMCore::States::WALK;
	}
	return DefaultNanoFSMCore::States::MINE;
}

std::string MineNano::GetStateName() const
{
	return "MineNano";
}