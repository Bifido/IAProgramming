#include "NanoBehaviour\GlobalNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Home.h"


GlobalNano::GlobalNano()
{
}

GlobalNano::~GlobalNano()
{
}

FSMStates GlobalNano::CheckTransition(NanoAgent& agent) const
{
	if (!agent.IsInStaminaRecovering() && !agent.HasStillStamina() && agent.GetTarget() != agent.GetHome()->GetPosition())
	{
		// Setting the HOME position as new target
		agent.SetTarget(agent.GetHome()->GetPosition());
		// go to state: WALK
		return DefaultNanoFSMCore::States::WALK;
	}
	else
		return DefaultNanoFSMCore::States::NOT_VALID;
}
