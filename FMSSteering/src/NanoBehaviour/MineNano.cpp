#include "NanoBehaviour\MineNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

MineNano::MineNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
MineNano::~MineNano()
{}

void MineNano::OnEnter(const NanoAgent* agent)
{}
void MineNano::OnExit(const NanoAgent* agent)
{}
void MineNano::Update(const NanoAgent* agent)
{}

State<NanoAgent>* MineNano::CheckTransition(const NanoAgent* agent) const
{
	return FSMCore<NanoAgent>::GetInstance().GetDefaultState();
}