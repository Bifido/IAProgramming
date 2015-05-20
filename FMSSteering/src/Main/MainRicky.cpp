#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "FiniteStateMachine.h"
#include "ViewComponent.h"
#include "ViewManager.h"
#include "SFML\System\Vector2.hpp"

#include "PassiveObj\Mine.h"

#include <iostream>
using namespace std;
using namespace sf;

NanoAgent newNano(10, 100);
Mine mine(1000);

void InitRicky(){
	FiniteStateMachine<NanoAgent> x;

	Vector2<float> pos(0.0f, 0.0f);
	newNano.SetPosition(pos);

	pos.x = 0.9f;
	pos.y = 0.5f;
	mine.SetPosition(pos);
	newNano.SetMine(&mine);

	ViewComponent* viewNano = new ViewComponent(ViewManager::DWARF, newNano.GetPosition(), 0); // LEAK
	newNano.SetViewComponent(viewNano);

	ViewComponent* viewMine = new ViewComponent(ViewManager::MINE, mine.GetPosition(), 0); // LEAK
	mine.SetViewComponent(viewMine);
}

void RunRicky(){

}

void StartRicky(){
	
}