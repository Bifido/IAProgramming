#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "FiniteStateMachine.h"
#include "ViewComponent.h"
#include "ViewManager.h"
#include "SFML\System\Vector2.hpp"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include "Constants.h"

#include <iostream>
using namespace std;
using namespace sf;




NanoAgent newNano(100, 1000, 5);
Mine mine(100);
Home home(1);
enum A
{
	FSM1 = 0
};
FiniteStateMachine<NanoAgent,1> x;

void InitRicky(){

	Vector2<float> pos(0.0f, 0.0f);
	newNano.SetPosition(pos);

	//pos.x = 0.5f;
	//pos.y = 0.7f;
	//mine.SetPosition(pos);
	//newNano.SetMine(&mine);

	home.SetPosition(MagicNumber::POS_NANO_HOUSE);
	newNano.SetHome(&home);

	mine.SetPosition(MagicNumber::POS_NANO_MINE);
	newNano.SetMine(&mine);

	ViewComponent* viewNano = new ViewComponent(ViewManager::DWARF, newNano.GetPosition(), 0); // LEAK
	newNano.SetViewComponent(viewNano);

	//ViewComponent* viewMine = new ViewComponent(ViewManager::MINE, mine.GetPosition(), 0); // LEAK
	//mine.SetViewComponent(viewMine);
}

void RunRicky(){
	x.Run(newNano);
}

void StartRicky(){
	
}