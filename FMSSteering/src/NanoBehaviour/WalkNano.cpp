#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

WalkNano::WalkNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
WalkNano::~WalkNano()
{}

void WalkNano::OnEnter(NanoAgent* agent) const
{}
void WalkNano::OnExit(NanoAgent* agent) const
{}
void WalkNano::Update(NanoAgent* agent) const
{}

State<NanoAgent>* WalkNano::CheckTransition(NanoAgent* agent) const
{ 
	return FSMCore<NanoAgent>::GetInstance().GetDefaultState(); 
}