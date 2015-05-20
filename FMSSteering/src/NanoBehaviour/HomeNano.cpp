#include "NanoBehaviour\HomeNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

HomeNano::HomeNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
HomeNano::~HomeNano()
{}

void HomeNano::OnEnter(const NanoAgent* agent)
{}
void HomeNano::OnExit(const NanoAgent* agent)
{}
void HomeNano::Update(const NanoAgent* agent)
{}

State<NanoAgent>* HomeNano::CheckTransition(const NanoAgent* agent) const
{
	//return FSMCore<NanoAgent>::GetInstance().GetDefaultState();
	return nullptr;
}