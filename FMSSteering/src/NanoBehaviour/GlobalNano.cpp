#include "NanoBehaviour\GlobalNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"


GlobalNano::GlobalNano()
{
}

GlobalNano::~GlobalNano()
{
}

FSMStates GlobalNano::CheckTransition(NanoAgent& agent) const
{
	if (!agent.HasStillStamina())
		return FSMCore<NanoAgent>::States::WALK;
	else
		return FSMCore<NanoAgent>::States::NOT_VALID;
}
