#include "NanoBehaviour\MineNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

MineNano::MineNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
MineNano::~MineNano()
{}

void MineNano::OnEnter(NanoAgent* agent) const
{}
void MineNano::OnExit(NanoAgent* agent) const
{}
void MineNano::Update(NanoAgent* agent) const
{}

State<NanoAgent>* MineNano::CheckTransition(NanoAgent* agent) const
{
	return FSMCore<NanoAgent>::GetInstance().GetDefaultState();
}