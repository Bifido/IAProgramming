#include "NanoBehaviour\HomeNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"
#include "ViewComponent.h"
#include "PassiveObj\Home.h"
#include "PassiveObj\Mine.h"

#include <iostream>

HomeNano::HomeNano()
{}
HomeNano::~HomeNano()
{}

void HomeNano::OnEnter( NanoAgent& agent) const
{
	if (agent.GetViewComponent() != nullptr)
	{
		agent.GetViewComponent()->SetDrawable(false);
	}

	std::cout << "CASA" << std::endl;
}
void HomeNano::OnExit( NanoAgent& agent) const
{
	if (agent.GetViewComponent() != nullptr)
	{
		agent.GetViewComponent()->SetDrawable(true);
	}
}
void HomeNano::Update( NanoAgent& agent) const
{
	agent.IncrementStamina(agent.GetHome()->GetStaminaRecovered());
}

FSMStates HomeNano::CheckTransition(NanoAgent& agent) const
{
	// if exist a home for this dwarf and he is full of stones, WALK TO HOME!
	if (agent.GetMine() != nullptr && agent.GetStamina() >= agent.MAX_STAMINA)
	{
		// Setting the mine position as new target
		agent.SetTarget(agent.GetMine()->GetPosition()); // TODO: Substitute this statement with agent->SetHomeAsTarget() ?
		// go to state: WALK
		return FSMCore<NanoAgent>::States::WALK;
	}
	// TODO: To implement
	return FSMCore<NanoAgent>::States::HOME;
}