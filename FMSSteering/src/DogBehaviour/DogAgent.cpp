#include "DogBehaviour\DogAgent.h"
#include "DogBehaviour\DogFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"
#include "PassiveObj\Fence.h"

DogAgent::DogAgent(std::string name, bool i_bIsCatching, bool m_bHasCatched) :
Agent(name),
m_oFsm(*this),
m_pFence(nullptr)
{
	this->SetVelocity(sf::Vector2<float>(DOG_SPEED));
	m_oFsm.AddFSM(DefaultDogFSMCore::GetInstance());
}

void DogAgent::SetFence(Fence* sheepFence){
	m_pFence = sheepFence;
}
const Fence* DogAgent::GetFence() const{
	return m_pFence;
}

void DogAgent::SetSheep(SheepAgent* i_pSheep)
{
	m_pSheepAgent = i_pSheep;
}
SheepAgent* DogAgent::GetSheep() const
{
	return m_pSheepAgent;
}

const bool DogAgent::CanStartCatching()
{
	if (m_pSheepAgent != nullptr)
	{
		if (!m_bHasCatched && !m_pSheepAgent->IsInFence())
		{
			sf::Vector2<float> sheepPos = m_pSheepAgent->GetPosition();
			float distance = sqrt(pow(sheepPos.x - this->GetPosition().x, 2) + pow(sheepPos.y - this->GetPosition().y, 2));
			if (distance > 0.f && distance < SHEEP_CATCHING_DISTANCE)
			{
				SetCatching(true);
				return true;
			}
		}
	}
	return false;
}
const bool DogAgent::IsCatching() const
{
	return m_bIsCatching;
}
void DogAgent::SetCatching(const bool i_bIsCatching){
	m_bIsCatching = i_bIsCatching;
}

const bool DogAgent::CanCatch()
{
	if (m_pSheepAgent != nullptr)
	{
		if (!m_bHasCatched)
		{
			sf::Vector2<float> sheepPos = m_pSheepAgent->GetPosition();
			float distance = sqrt(pow(sheepPos.x - this->GetPosition().x, 2) + pow(sheepPos.y - this->GetPosition().y, 2));
			if (distance < SHEEP_CATCHED_DISTANCE)
			{
				SetCatched(true);
				m_pSheepAgent->SetCatched(true);
				return true;
			}
		}
	}
	return false;
}
const bool DogAgent::HasCatch() const
{
	return m_bHasCatched;
}
void DogAgent::SetCatched(const bool i_bHaveCatched)
{
	m_bHasCatched = i_bHaveCatched;
}

void DogAgent::FSMAdd(FSMCore<DogAgent>* sharedStates){
	m_oFsm.AddFSM(sharedStates);
}
void DogAgent::FSMRemove(){
	m_oFsm.RemoveFSM();
}
void DogAgent::FSMRun(float dt){
	m_oFsm.Run(dt);
}