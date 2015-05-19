#include "NanoBehaviour\HomeNano.h"
//#include "NanoBehaviour\NanoFSMCore.h"

HomeNano::HomeNano()
{}
HomeNano::~HomeNano()
{}

void HomeNano::OnEnter(NanoAgent*)
{}
void HomeNano::OnExit(NanoAgent*)
{}
void HomeNano::Update(NanoAgent*)
{}

State<NanoAgent>* HomeNano::CheckTransition()
{
	//return FSMCore<NanoAgent>::GetInstance().GetDefaultState();
	return nullptr;
}