#include "NanoBehaviour\MineNano.h"
#include "NanoBehaviour\NanoFSMCore.h"

MineNano::MineNano()
{}
MineNano::~MineNano()
{}

void MineNano::OnEnter(NanoAgent*)
{}
void MineNano::OnExit(NanoAgent*)
{}
void MineNano::Update(NanoAgent*)
{}

State<NanoAgent>* MineNano::CheckTransition()
{
	return FSMCore<NanoAgent>::GetInstance().GetDefaultState();
}