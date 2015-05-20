#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "FiniteStateMachine.h"

#include "ViewComponent.h"

void InitMarco(){
	FiniteStateMachine<NanoAgent> x;
	
	NanoAgent newNano(10,100);
	ViewComponent* viewNano = new ViewComponent(ViewManager::DWARF, newNano.GetPosition(), 0);
	newNano.SetViewComponent(viewNano);

	//FSMCore<NanoAgent>& x = FSMCore<NanoAgent>::GetInstance();
}

void StartMarco(){
}

void RunMarco(){

}