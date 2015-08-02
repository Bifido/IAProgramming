#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\StateBruca.h"
#include "SheepBehaviour\GlobalSheep.h"

#include <assert.h>
#include <iostream>

using namespace std;

DefaultSheepFSMCore::DefaultSheepFSMCore()
{
	//TODO check from here
	/*statesArray[States::ESCAPE_FROM_FENCE] = new EscapeFromFenceSheep();
	statesArray[States::ESCAPE_FROM_DOG] = new EscapeFromDogSheep();
	statesArray[States::BACK_IN_FENCE] = new BackInFence();*/
	statesArray[States::BRUCA] = new StateBruca();

	//NEVER USED. HERE ONLY TO SATISFY DefaultSheepFSMCore that inherit from FSMCore.h with pure virtual GetGlobalArc()
	globalArc = new GlobalSheep();
}

DefaultSheepFSMCore::~DefaultSheepFSMCore()
{

}

FSMCore<SheepAgent>* DefaultSheepFSMCore::GetInstance()
{
	static DefaultSheepFSMCore m_instance;
	return &m_instance;
}

State<SheepAgent>* DefaultSheepFSMCore::GetDefaultState() const
{
	cout << "Default State Sheep = " << States::BRUCA << endl;
	return statesArray[States::BRUCA];
}

State<SheepAgent>* DefaultSheepFSMCore::GetState(FSMStates stateId) const
{
	assert(stateId < States::COUNT && stateId != States::NOT_VALID);

	return statesArray[stateId];
}

GlobalArc<SheepAgent>* DefaultSheepFSMCore::GetGlobalArc() const
{
	return globalArc;
}

bool DefaultSheepFSMCore::IsStateValid(FSMStates stateId) const
{
	return (stateId != States::NOT_VALID);
}

FSMStates DefaultSheepFSMCore::GetNotValidState() const
{
	return States::NOT_VALID;
}