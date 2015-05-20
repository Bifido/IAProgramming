#include "NanoBehaviour\IdleNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"

#include <assert.h>

IdleNano::IdleNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
IdleNano::~IdleNano()
{}

void IdleNano::OnEnter(NanoAgent* agent) const
{}
void IdleNano::OnExit(NanoAgent* agent) const
{}
void IdleNano::Update(NanoAgent* agent) const
{
	// TODO: Sprite animation?
}

State<NanoAgent>* IdleNano::CheckTransition(NanoAgent* agent) const
{
	assert(agent != nullptr);

	// if exist a mine for this dwarf and has at least 1 stone, WALK TO MINE!
	if (agent->GetMine() != nullptr && agent->GetMine()->GetActualStonesNumber() > 0){
		return m_fsmCore.GetState(FSMCore<NanoAgent>::WALK);
	}
}