#include "NanoBehaviour\NanoAgent.h"
#include "SheepBehaviour\SheepAgent.h"
#include "DogBehaviour\DogAgent.h"

#include "PassiveObj\Fence.h"
#include "PassiveObj\Home.h"
#include "PassiveObj\Mine.h"

#include "ViewComponent.h"
#include "ViewManager.h"

#include "SFML\System\Vector2.hpp"

using namespace sf;

NanoAgent newNano("Nano", 100, 10, 5);
SheepAgent sheep("Sheep");
DogAgent dog("Dog");

Mine mine(100);
Home home(1);
Fence fence(MagicNumber::POS_BACKGROUND_FENCE, MagicNumber::FENCE_SIZE);

void InitMarco()
{
	home.SetPosition(MagicNumber::POS_NANO_HOUSE);
	mine.SetPosition(MagicNumber::POS_NANO_MINE);

	newNano.SetHome(&home);
	newNano.SetMine(&mine);
	newNano.SetMaxSpeed(0.01f);

	Vector2<float> pos(MagicNumber::POS_NANO_HOUSE);
	newNano.SetPosition(pos);

	ViewComponent* viewNano = new ViewComponent(ViewManager::DWARF, newNano.GetPosition(), 0);
	newNano.SetViewComponent(viewNano);

	Vector2<float> pos4(0.07f, 0.58f);
	sheep.SetPosition(pos4);
	ViewComponent* viewSheep = new ViewComponent(ViewManager::SHEEP, sheep.GetPosition(), 0);
	sheep.SetViewComponent(viewSheep);
	sheep.SetFence(&fence);

	sheep.SetTarget(fence.GetRandomPointInside());
	sheep.SetMaxSpeed(0.01f);

	Vector2<float> pos5(0.6f, 0.6f);
	dog.SetPosition(pos5);
	ViewComponent* viewNano5 = new ViewComponent(ViewManager::DOG, dog.GetPosition(), 0);
	dog.SetViewComponent(viewNano5);
	dog.SetFence(&fence);
	dog.SetSheep(&sheep);

	dog.SetTarget(fence.GetRandomPointOutside());
	dog.SetMaxSpeed(0.012f);
	sheep.SetDog(&dog);

}

void StartMarco(){
}

void RunMarco(){
	newNano.FSMRun(MagicNumber::deltaTime);
	sheep.FSMRun(MagicNumber::deltaTime);
	dog.FSMRun(MagicNumber::deltaTime);

}