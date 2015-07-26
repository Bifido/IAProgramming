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
Fence* SheepAgent::GetFence() const{
	return m_oFence;
}

const bool SheepAgent::IsInFence() const{
	return m_bIsInFence;
}
const bool SheepAgent::IsEscaping() const{
	return m_bIsEscaping;
}

//TODO continue under here

void SheepAgent::SetInFence(const bool inFence){

}
void SheepAgent::SetEscaping(const bool escaping){

}


void SheepAgent::FSMAdd(FSMCore<SheepAgent>* sharedStates){

}
void SheepAgent::FSMRemove(){

}
void SheepAgent::FSMRun(){

}