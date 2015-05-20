#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "FiniteStateMachine.h"
#include "ViewComponent.h"
#include "SFML\System\Vector2.hpp"
#include "Constants.h"

#include <iostream>
using namespace std;
using namespace sf;
using namespace MagicNumber;

NanoAgent newNano(10, 100);
NanoAgent newNano2(10, 100);
NanoAgent newNano3(10, 100);
NanoAgent newNano4(10, 100);		//IS A SHEEP!

void InitVale(){
	FiniteStateMachine<NanoAgent> x;

	Vector2<float> pos(0.5f, 0.5f);
	newNano.SetPosition(pos);
	ViewComponent* viewNano = new ViewComponent(ViewManager::DWARF, newNano.GetPosition(), 0);
	newNano.SetViewComponent(viewNano);

	newNano2.SetPosition(POS_NANO_HOUSE);
	ViewComponent* viewNano2 = new ViewComponent(ViewManager::DWARF, newNano2.GetPosition(), 0);
	newNano2.SetViewComponent(viewNano2);

	newNano3.SetPosition(POS_NANO_MINE);
	ViewComponent* viewNano3 = new ViewComponent(ViewManager::DWARF, newNano3.GetPosition(), 0);
	newNano3.SetViewComponent(viewNano3);

	Vector2<float> pos4(0.07f, 0.58f);
	newNano4.SetPosition(pos4);
	ViewComponent* viewNano4 = new ViewComponent(ViewManager::SHEEP, newNano4.GetPosition(), 0);
	newNano4.SetViewComponent(viewNano4);

}

void StartVale(){
}

void RunVale(){
}