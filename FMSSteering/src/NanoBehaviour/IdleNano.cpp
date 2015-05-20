#include "NanoBehaviour\IdleNano.h"
#include "NanoBehaviour\NanoFSMCore.h"

IdleNano::IdleNano()
{}
IdleNano::~IdleNano()
{}

void IdleNano::OnEnter(NanoAgent*)
{}
void IdleNano::OnExit(NanoAgent*)
{}
void IdleNano::Update(NanoAgent*)
{}

State<NanoAgent>* IdleNano::CheckTransition()
{
	return FSMCore<NanoAgent>::GetInstance().GetDefaultState();
}