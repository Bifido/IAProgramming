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
	if (!agent.IsInStaminaRecovering() && !agent.HasStillStamina())
	{
		// Setting the mine position as new target
		agent.SetTarget(agent.GetHome()->GetPosition()); // TODO: Substitute this statement with agent->SetHomeAsTarget() ?
		// go to state: WALK
		return FSMCore<NanoAgent>::States::WALK;
	}
	else
		return FSMCore<NanoAgent>::States::NOT_VALID;
}
