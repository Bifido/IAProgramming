#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\NanoFSMCore.h"

WalkNano::WalkNano()
{}
WalkNano::~WalkNano()
{}

void WalkNano::OnEnter(NanoAgent*)
{}
void WalkNano::OnExit(NanoAgent*)
{}
void WalkNano::Update(NanoAgent*)
{}

State<NanoAgent>* WalkNano::CheckTransition()
{ 
	return FSMCore<NanoAgent>::GetInstance().GetDefaultState(); 
}