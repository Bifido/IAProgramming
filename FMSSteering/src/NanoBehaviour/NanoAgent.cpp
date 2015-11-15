#include "NanoBehaviour\NanoAgent.h"
#include "NanoBehaviour\NanoFSMCore.h"

using namespace sf;

NanoAgent::NanoAgent(std::string name,  int maxStone, unsigned int maxStamina, unsigned int stonesRatio,
	unsigned int staminaUsage, unsigned int staminaRecover) :
	Agent(name),
	MAX_STAMINA(maxStamina),
	MAX_STONE(maxStone),
	STONES_RATIO(stonesRatio),
	STAMINA_USAGE(staminaUsage),
	STAMINA_RECOVER(staminaRecover),
	fsm(*this),
	m_stamina(MAX_STAMINA),
	m_numOfCarriedStones(0),
	myMine(nullptr),
	myHome(nullptr)
{
	fsm.AddFSM(DefaultNanoFSMCore::GetInstance());
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
	m_stamina = newStamina < MAX_STAMINA ? newStamina : MAX_STAMINA;
}

unsigned int NanoAgent::IncrementStamina(unsigned int staminaToAdd){

	m_stamina += staminaToAdd;
	m_stamina = m_stamina < MAX_STAMINA ? m_stamina : MAX_STAMINA;

	return m_stamina;
}

unsigned int NanoAgent::DecrementStamina(unsigned int staminaLost){
	m_stamina = (m_stamina > staminaLost) ? (m_stamina - staminaLost) : 0;

	return m_stamina;
}

void NanoAgent::SetCarriedStonesNumber(unsigned int newCarriedStonesNumber){
	m_numOfCarriedStones = newCarriedStonesNumber < MAX_STONE ? newCarriedStonesNumber : MAX_STONE;
}

unsigned int NanoAgent::IncrementStoneCarried(unsigned int stoneToAdd){
	m_numOfCarriedStones += stoneToAdd;
	m_numOfCarriedStones = m_numOfCarriedStones < MAX_STONE ? m_numOfCarriedStones : MAX_STONE;
	
	return m_numOfCarriedStones;
}

unsigned int NanoAgent::DecrementStoneCarried(unsigned int stoneToRemove){
	m_numOfCarriedStones = (m_numOfCarriedStones > stoneToRemove) ? (m_numOfCarriedStones - stoneToRemove) : 0;

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

void NanoAgent::FSMAdd(FSMCore<NanoAgent>* sharedStates)
{
	fsm.AddFSM(sharedStates);
}
void NanoAgent::FSMRemove()
{
	fsm.RemoveFSM();
}
void NanoAgent::FSMRun(float dt)
{
	fsm.Run(dt);
}
