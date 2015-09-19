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
	agent.FSMAdd(SubHomeNanoFSMCore::GetInstance());
}
void HomeNano::OnExit( NanoAgent& agent) const
{
	if (agent.GetViewComponent() != nullptr)
	{
		agent.GetViewComponent()->SetDrawable(true);
	}
	std::cout << "HOUSE out stamina " << agent.GetStamina() << " stones " << agent.GetCarriedStonesNumber() << std::endl;
	agent.FSMRemove();
}
void HomeNano::Update(NanoAgent& agent, float dt) const
{
}

FSMStates HomeNano::CheckTransition(NanoAgent& agent) const
{
	// if exist a mine for this dwarf and he is full of stamina, WALK TO MINE!
	if (!agent.IsInStaminaRecovering() && agent.GetMine() != nullptr && agent.GetStamina() >= agent.MAX_STAMINA && agent.GetCarriedStonesNumber() <= 0)
	{
		// Setting the mine position as new target
		agent.SetTarget(agent.GetMine()->GetPosition()); // TODO: Substitute this statement with agent->SetHomeAsTarget() ?
		// go to state: WALK
		return DefaultNanoFSMCore::States::WALK;
	}

	return DefaultNanoFSMCore::States::HOME;
}

std::string HomeNano::GetStateName() const
{
	return "HomeNano";
}