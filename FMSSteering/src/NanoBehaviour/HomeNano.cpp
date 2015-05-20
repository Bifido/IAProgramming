#include "NanoBehaviour\HomeNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

HomeNano::HomeNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
HomeNano::~HomeNano()
{}

void HomeNano::OnEnter( NanoAgent* agent) const
{}
void HomeNano::OnExit( NanoAgent* agent) const
{}
void HomeNano::Update( NanoAgent* agent) const
{}

State<NanoAgent>* HomeNano::CheckTransition( NanoAgent* agent) const
{
	//return FSMCore<NanoAgent>::GetInstance().GetDefaultState();
	return nullptr;
}