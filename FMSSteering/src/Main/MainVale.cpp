#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "FiniteStateMachine.h"
#include "ViewComponent.h"
#include "SFML\System\Vector2.hpp"

#include <iostream>
using namespace std;
using namespace sf;

NanoAgent newNano(10, 100);

void InitVale(){
	FiniteStateMachine<NanoAgent> x;

	Vector2<float> pos(0.5f, 0.5f);
	newNano.SetPosition(pos);
	ViewComponent* viewNano = new ViewComponent(ViewManager::DWARF, newNano.GetPosition(), 0); // LEAK
	newNano.SetViewComponent(viewNano);

}

void StartVale(){
}

void RunVale(){
}