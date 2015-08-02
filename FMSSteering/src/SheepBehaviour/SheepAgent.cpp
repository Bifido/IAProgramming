#include "SheepBehaviour\SheepAgent.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "PassiveObj\Fence.h"

SheepAgent::SheepAgent(bool isInFence, bool isEscaping,bool isCatched):
	m_bIsInFence(isInFence),
	m_bIsEscaping(isEscaping),
	m_bIsCatched(isCatched),
	m_oFsm(*this),
	m_oFence(nullptr)
	{
	this->SetVelocity(sf::Vector2<float>(0.005f, 0.005f));
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
void SheepAgent::SetCatched(const bool catched){
	m_bIsCatched = catched;
}

void SheepAgent::FSMAdd(FSMCore<SheepAgent>* sharedStates){
	m_oFsm.AddFSM(sharedStates);
}
void SheepAgent::FSMRemove(){
	m_oFsm.RemoveFSM();
}
void SheepAgent::FSMRun(){
	m_oFsm.Run();
}