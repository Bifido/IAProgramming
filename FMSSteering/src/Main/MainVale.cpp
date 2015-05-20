#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "FiniteStateMachine.h"
#include "ViewComponent.h"
#include "SFML\System\Vector2.hpp"

#include <iostream>
using namespace std;
using namespace sf;

void InitVale(){
	FiniteStateMachine<NanoAgent> x;

	NanoAgent newNano(10, 100);
	Vector2<float> pos(0.0f, 0.0f);
	newNano.SetPosition(pos);
	ViewComponent* viewNano = new ViewComponent(ViewManager::DWARF, newNano.GetPosition(), 0);
	newNano.SetViewComponent(viewNano);

	//FSMCore<NanoAgent>& x = FSMCore<NanoAgent>::GetInstance();
}

void StartVale(){
}

void RunVale(){
}