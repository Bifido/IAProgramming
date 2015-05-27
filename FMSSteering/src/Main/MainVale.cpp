#include "Constants.h"
#include "FiniteStateMachine.h"
#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "PassiveObj\Home.h";
#include "PassiveObj\Mine.h";
#include "ViewComponent.h"
#include "ViewManager.h"
#include "SFML\System\Vector2.hpp"

#include <iostream>
using namespace std;
using namespace sf;
using namespace MagicNumber;

NanoAgent newNano(10, 100);
NanoAgent newNano2(10, 100);
NanoAgent newNano3(10, 100);
NanoAgent newNano4(10, 100);		//IS A SHEEP!
NanoAgent newNano5(10, 100);		//IS A DOG!
Mine mine(1000);
Home home(1);

void InitVale(){
	FiniteStateMachine<NanoAgent,0> x;

	newNano.SetMine(&mine);

	home.SetPosition(MagicNumber::POS_NANO_HOUSE);
	newNano.SetHome(&home);

	mine.SetPosition(MagicNumber::POS_NANO_MINE);
	newNano.SetMine(&mine);

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

	Vector2<float> pos5(0.6f, 0.6f);
	newNano5.SetPosition(pos5);
	ViewComponent* viewNano5 = new ViewComponent(ViewManager::DOG, newNano5.GetPosition(), 0);
	newNano5.SetViewComponent(viewNano5);

}

void StartVale(){
}

void RunVale(){
}