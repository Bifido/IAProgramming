#include "NanoBehaviour\MineNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"
#include "PassiveObj\Home.h"
#include "ViewComponent.h"

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
}
void MineNano::OnExit(NanoAgent& agent) const
{
	if (agent.GetViewComponent() != nullptr)
	{
		agent.GetViewComponent()->SetDrawable(true);
	}
}
void MineNano::Update(NanoAgent& agent) const
{
	agent.IncrementStoneCarried(1);
}

FSMStates MineNano::CheckTransition(NanoAgent& agent) const
{
	// if exist a home for this dwarf and he is full of stones, WALK TO HOME!
	if (agent.GetHome() != nullptr && agent.HasReachedMaxStone())
	{
		// Setting the mine position as new target
		agent.SetTarget(agent.GetHome()->GetPosition()); // TODO: Substitute this statement with agent->SetHomeAsTarget() ?
		// go to state: WALK
		return FSMCore<NanoAgent>::States::WALK;
	}
	// TODO: To implement
	return FSMCore<NanoAgent>::States::MINE;
}