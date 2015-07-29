#include "Constants.h"
#include "FiniteStateMachine.h"
#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"
#include "PassiveObj\Home.h";
#include "PassiveObj\Mine.h";
#include "ViewComponent.h"
#include "ViewManager.h"
#include "SFML\System\Vector2.hpp"

#include <iostream>
using namespace std;
using namespace sf;
using namespace MagicNumber;

NanoAgent newNano(100, 10, 5);
SheepAgent sheep;

Mine mine(100);
Home home(1);
Fence fence();

enum A
{
	FSM1 = 0
};

void InitVale(){
	//FiniteStateMachine<NanoAgent> x;

	home.SetPosition(MagicNumber::POS_NANO_HOUSE);
	mine.SetPosition(MagicNumber::POS_NANO_MINE);

	newNano.SetHome(&home);
	newNano.SetMine(&mine);

	Vector2<float> pos(MagicNumber::POS_NANO_HOUSE);
	newNano.SetPosition(pos);

	ViewComponent* viewNano = new ViewComponent(ViewManager::DWARF, newNano.GetPosition(), 0);
	newNano.SetViewComponent(viewNano);

	Vector2<float> pos4(0.07f, 0.58f);
	sheep.SetPosition(pos4);
	ViewComponent* viewSheep = new ViewComponent(ViewManager::SHEEP, sheep.GetPosition(), 0);
	sheep.SetViewComponent(viewSheep);

	/*Vector2<float> pos5(0.6f, 0.6f);
	newNano5.SetPosition(pos5);
	ViewComponent* viewNano5 = new ViewComponent(ViewManager::DOG, newNano5.GetPosition(), 0);
	newNano5.SetViewComponent(viewNano5);*/

}

void StartVale(){
}

void RunVale(){
	newNano.FSMRun();
}


