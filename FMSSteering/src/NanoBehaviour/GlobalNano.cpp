#include "NanoBehaviour\GlobalNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"


GlobalNano::GlobalNano()
	:GlobalArc(FSMCore < NanoAgent > ::GetInstance())
{
}

GlobalNano::~GlobalNano()
{
}

State<NanoAgent>* GlobalNano::CheckTransition(NanoAgent& agent) const
{
	if (!agent.HasStillStamina())
		return m_fsmCore.GetState(m_fsmCore.WALK);
	else
		return nullptr;
}
