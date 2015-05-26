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
	agent.SetStaminaRecovering(true);
	if (agent.GetViewComponent() != nullptr)
	{
		agent.GetViewComponent()->SetDrawable(false);
	}
	std::cout << "HOUSE in stamina " << agent.GetStamina() << " stones " << agent.GetCarriedStonesNumber() << std::endl;
}
void HomeNano::OnExit( NanoAgent& agent) const
{
	agent.SetStaminaRecovering(false);
	if (agent.GetViewComponent() != nullptr)
	{
		agent.GetViewComponent()->SetDrawable(true);
	}
	std::cout << "HOUSE out stamina " << agent.GetStamina() << " stones " << agent.GetCarriedStonesNumber() << std::endl;
}
void HomeNano::Update( NanoAgent& agent) const
{
	agent.IncrementStamina(agent.GetHome()->GetStaminaRecovered() * agent.STAMINA_RECOVER);
	if (agent.GetCarriedStonesNumber() > 0)
		agent.DecrementStoneCarried(agent.STONES_RATIO);
}

FSMStates HomeNano::CheckTransition(NanoAgent& agent) const
{
	// if exist a mine for this dwarf and he is full of stamina, WALK TO MINE!
	if (agent.GetMine() != nullptr && agent.GetStamina() >= agent.MAX_STAMINA)
	{
		// Setting the mine position as new target
		agent.SetTarget(agent.GetMine()->GetPosition()); // TODO: Substitute this statement with agent->SetHomeAsTarget() ?
		// go to state: WALK
		return FSMCore<NanoAgent,0>::States::WALK;
	}
	// TODO: To implement
	return FSMCore<NanoAgent, 0>::States::HOME;
}