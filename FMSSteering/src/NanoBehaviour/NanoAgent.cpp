#include <assert.h>
#include "NanoBehaviour\NanoAgent.h"

using namespace sf;

NanoAgent::NanoAgent(unsigned int maxStone, unsigned int maxStamina) :
	MAX_STAMINA(maxStamina),
	MAX_STONE(maxStone),
	stamina(MAX_STAMINA),
	numOfCarriedStones(0),
	myMine(nullptr),
	myHome(nullptr){ 
}

unsigned int NanoAgent::GetStamina() const{
	return stamina;
}

unsigned int NanoAgent::GetCarriedStonesNumber() const{
	return numOfCarriedStones;
}

Home* NanoAgent::GetHome() const{
	return myHome;
}

Mine* NanoAgent::GetMine() const{
	return myMine;
}

void NanoAgent::SetHome(Home* nanoHome){
	myHome = nanoHome;
}

void NanoAgent::SetMine(Mine* nanoMine){
	myMine = nanoMine;
}


void NanoAgent::SetStamina(unsigned int newStamina){
	// the stamina can't be a negative value **DEPRECATED**
	//assert(newStamina >= 0);

	stamina = newStamina < MAX_STAMINA ? newStamina : MAX_STAMINA;
}

unsigned int NanoAgent::IncrementStamina(unsigned int staminaToAdd){
	// the stamina to add can't be a negative value **DEPRECATED**
	//assert(staminaToAdd >= 0);

	stamina += staminaToAdd;
	stamina = stamina < MAX_STAMINA ? stamina : MAX_STAMINA;

	return stamina;
}

unsigned int NanoAgent::DecrementStamina(unsigned int staminaLost){
	// the stamina lost can't be a negative value **DEPRECATED**
	//assert(staminaLost >= 0);

	stamina -= staminaLost;
	stamina = stamina > 0 ? stamina : 0;

	return stamina;
}

void NanoAgent::SetCarriedStonesNumber(unsigned int newCarriedStonesNumber){
	// the carried stone number can't be a negative value **DEPRECATED**
	//assert(newCarriedStonesNumber >= 0);

	numOfCarriedStones = newCarriedStonesNumber < MAX_STONE ? newCarriedStonesNumber : MAX_STONE;
}

unsigned int NanoAgent::IncrementStoneCarried(unsigned int stoneToAdd){
	// the number of carried stone added can't be a negative value **DEPRECATED**
	//assert(stoneToAdd >= 0);

	numOfCarriedStones += stoneToAdd;
	numOfCarriedStones = numOfCarriedStones < MAX_STONE ? numOfCarriedStones : MAX_STONE;
	
	return numOfCarriedStones;
}

unsigned int NanoAgent::DecrementStoneCarried(unsigned int stoneToRemove){
	// the number of carried stone dropped can't be a negative value **DEPRECATED**
	//assert(stoneToRemove >= 0);

	numOfCarriedStones -= stoneToRemove;
	numOfCarriedStones = numOfCarriedStones > 0 ? numOfCarriedStones : 0;

	return numOfCarriedStones;
}

bool NanoAgent::HasReachedMaxStone() const{
	return (numOfCarriedStones == MAX_STONE);
}

bool NanoAgent::HasStillStamina() const{
	return (stamina > 0);
}

bool NanoAgent::HasEnoughStamina(unsigned int staminaRequired) const{
	return (stamina >= staminaRequired);
}

NanoAgent::~NanoAgent(){ }