#include "SheepBehaviour\SheepAgent.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "PassiveObj\Fence.h"

SheepAgent::SheepAgent(std::string name,bool isInFence, bool isEscaping,bool isCatched):
	Agent(name),
	m_bIsInFence(isInFence),
	m_bIsEscaping(isEscaping),
	m_bIsCatched(isCatched),
	m_oFsm(*this),
	m_oFence(nullptr)
	{
	this->SetVelocity(sf::Vector2<float>(SHEEP_SPEED));
	m_oFsm.AddFSM(DefaultSheepFSMCore::GetInstance());
}

void SheepAgent::SetFence(Fence* sheepFence){
	m_oFence = sheepFence;
}
const Fence* SheepAgent::GetFence() const{
	return m_oFence;
}

const bool SheepAgent::IsInFence() const{
	return m_bIsInFence;
}
const bool SheepAgent::IsEscaping() const{
	return m_bIsEscaping;
}
const bool SheepAgent::IsCatched() const{
	return m_bIsCatched;
}

void SheepAgent::SetInFence(const bool inFence){
	m_bIsInFence = inFence;
}
void SheepAgent::SetEscaping(const bool isEscaping){
	m_bIsEscaping = isEscaping;
}
void SheepAgent::SetCatched(const bool i_bCatched)
{
	m_bIsCatched = i_bCatched;
}

void SheepAgent::SetDog(DogAgent* i_pDog)
{
	m_pDogAgent = i_pDog;
}
DogAgent* SheepAgent::GetDog() const
{
	return m_pDogAgent;
}

void SheepAgent::FSMAdd(FSMCore<SheepAgent>* sharedStates){
	m_oFsm.AddFSM(sharedStates);
}
void SheepAgent::FSMRemove(){
	m_oFsm.RemoveFSM();
}
void SheepAgent::FSMRun(float dt){
	m_oFsm.Run(dt);
}