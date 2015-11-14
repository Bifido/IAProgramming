#include "NanoBehaviour\NanoAgent.h"
#include "SheepBehaviour\SheepAgent.h"
#include "DogBehaviour\DogAgent.h"

#include "PassiveObj\Fence.h"
#include "PassiveObj\Home.h"
#include "PassiveObj\Mine.h"

#include "ViewComponent.h"

NanoAgent newNano("Nano", 100, 10, 5);
SheepAgent sheep("Sheep");
DogAgent dog("Dog");

Mine mine(100);
Home home(1);
Fence fence(MagicNumber::POS_BACKGROUND_FENCE, MagicNumber::FENCE_SIZE);

void InitMarco(){

}

void StartMarco(){
}

void RunMarco(){
	newNano.FSMRun(MagicNumber::deltaTime);
	sheep.FSMRun(MagicNumber::deltaTime);
	dog.FSMRun(MagicNumber::deltaTime);

}