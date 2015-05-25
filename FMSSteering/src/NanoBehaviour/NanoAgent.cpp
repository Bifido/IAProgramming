#include <assert.h>
#include "NanoBehaviour\NanoAgent.h"

using namespace sf;

NanoAgent::NanoAgent(unsigned int maxStone, unsigned int maxStamina, unsigned int stonesRatio,
	unsigned int staminaUsage, unsigned int staminaRecover) :
	MAX_STAMINA(maxStamina),
	MAX_STONE(maxStone),
	STONES_RATIO(stonesRatio),
	STAMINA_USAGE(staminaUsage),
	STAMINA_RECOVER(staminaRecover),
	m_stamina(MAX_STAMINA),
	m_numOfCarriedStones(0),
	myMine(nullptr),
	myHome(nullptr){ 
}

unsigned int NanoAgent::GetStamina() const{
	return m_stamina;
}

unsigned int NanoAgent::GetCarriedStonesNumber() const{
	return m_numOfCarriedStones;
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

	m_stamina = newStamina < MAX_STAMINA ? newStamina : MAX_STAMINA;
}

unsigned int NanoAgent::IncrementStamina(unsigned int staminaToAdd){
	// the stamina to add can't be a negative value **DEPRECATED**
	//assert(staminaToAdd >= 0);

	m_stamina += staminaToAdd;
	m_stamina = m_stamina < MAX_STAMINA ? m_stamina : MAX_STAMINA;

	return m_stamina;
}

unsigned int NanoAgent::DecrementStamina(unsigned int staminaLost){
	// the stamina lost can't be a negative value **DEPRECATED**
	//assert(staminaLost >= 0);

	m_stamina -= staminaLost;
	m_stamina = m_stamina > 0 ? m_stamina : 0;

	return m_stamina;
}

void NanoAgent::SetCarriedStonesNumber(unsigned int newCarriedStonesNumber){
	// the carried stone number can't be a negative value **DEPRECATED**
	//assert(newCarriedStonesNumber >= 0);

	m_numOfCarriedStones = newCarriedStonesNumber < MAX_STONE ? newCarriedStonesNumber : MAX_STONE;
}

unsigned int NanoAgent::IncrementStoneCarried(unsigned int stoneToAdd){
	// the number of carried stone added can't be a negative value **DEPRECATED**
	//assert(stoneToAdd >= 0);

	m_numOfCarriedStones += stoneToAdd;
	m_numOfCarriedStones = m_numOfCarriedStones < MAX_STONE ? m_numOfCarriedStones : MAX_STONE;
	
	return m_numOfCarriedStones;
}

unsigned int NanoAgent::DecrementStoneCarried(unsigned int stoneToRemove){
	// the number of carried stone dropped can't be a negative value **DEPRECATED**
	//assert(stoneToRemove >= 0);

	m_numOfCarriedStones -= stoneToRemove;
	m_numOfCarriedStones = m_numOfCarriedStones > 0 ? m_numOfCarriedStones : 0;

	return m_numOfCarriedStones;
}

bool NanoAgent::HasReachedMaxStone() const{
	return (m_numOfCarriedStones >= MAX_STONE);
}

bool NanoAgent::HasStillStamina() const{
	return (m_stamina > 0);
}

bool NanoAgent::HasEnoughStamina(unsigned int staminaRequired) const{
	return (m_stamina >= staminaRequired);
}

void NanoAgent::SetStaminaRecovering(bool staminaRecovering)
{
	m_staminaRecovering = staminaRecovering;
}

bool NanoAgent::IsInStaminaRecovering() const
{
	return m_staminaRecovering;
}

NanoAgent::~NanoAgent(){ }