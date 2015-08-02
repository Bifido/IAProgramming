#include "SheepBehaviour\SheepAgent.h"
#include "SheepBehaviour\SheepFSMCore.h"

SheepAgent::SheepAgent(bool isInFence, bool isEscaping):
	m_bIsInFence(isInFence),
	m_bIsEscaping(isEscaping),
	m_oFsm(*this),
	m_oFence(nullptr)
	{
	
	m_oFsm.AddFSM(DefaultSheepFSMCore::GetInstance());
}

void SheepAgent::SetFence(const Fence& sheepFence){

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

void SheepAgent::SetInFence(const bool inFence){
	m_bIsInFence = inFence;
}
void SheepAgent::SetEscaping(const bool isEscaping){
	m_bIsEscaping = isEscaping;
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