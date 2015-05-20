#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

WalkNano::WalkNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
WalkNano::~WalkNano()
{}

void WalkNano::OnEnter(const NanoAgent* agent)
{}
void WalkNano::OnExit(const NanoAgent* agent)
{}
void WalkNano::Update(const NanoAgent* agent)
{}

State<NanoAgent>* WalkNano::CheckTransition(const NanoAgent* agent) const
{ 
	return FSMCore<NanoAgent>::GetInstance().GetDefaultState(); 
}