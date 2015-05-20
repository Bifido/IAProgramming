#include "NanoBehaviour\IdleNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

IdleNano::IdleNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
IdleNano::~IdleNano()
{}

void IdleNano::OnEnter(const NanoAgent* agent)
{}
void IdleNano::OnExit(const NanoAgent* agent)
{}
void IdleNano::Update(const NanoAgent* agent)
{}

State<NanoAgent>* IdleNano::CheckTransition(const NanoAgent* agent) const
{
	return FSMCore<NanoAgent>::GetInstance().GetDefaultState();
}