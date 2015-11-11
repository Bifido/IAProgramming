#include "DogBehaviour\StateCatchingSheep.h"
#include "DogBehaviour\DogFSMCore.h"
#include "DogBehaviour\DogAgent.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include "Steering\SteeringFactory.h"
#include "Steering\Steering.h"

#include <assert.h>
#include <iostream>

using namespace std;

StateCatchingSheep::StateCatchingSheep()
{
}
StateCatchingSheep::~StateCatchingSheep()
{}

void StateCatchingSheep::OnEnter(DogAgent& agent) const{
	Steering* ptr = agent.SetCurrentSteering(SteeringFactory::Seek);

	sf::Vector2<float> target = agent.GetSheep()->GetPosition();
	agent.SetTarget(target);
	agent.GetSheep()->SetEscaping(true);

	ptr->Init(&agent);
}

void StateCatchingSheep::OnExit(DogAgent& agent) const{
	agent.SetCatched(false);
	agent.RemoveCurrentSteering();
}

void StateCatchingSheep::Update(DogAgent& agent, float dt) const {

	agent.GetCurrentSteering()->Update(dt);
}

FSMStates StateCatchingSheep::CheckTransition(DogAgent& agent) const
{

	if (!agent.HasCatch())
	{
		//Check if dog catched the Sheep
		if (agent.CanCatch()){
			agent.SetCatched(true);
			agent.GetSheep()->SetCatched(true);
		}
		sf::Vector2<float> target = agent.GetSheep()->GetPosition();
		agent.SetTarget(target);
		return DefaultDogFSMCore::States::CATCHING;
	}
	else
	{
		return DefaultDogFSMCore::States::SWAN;
	}
}


std::string StateCatchingSheep::GetStateName() const
{
	return "State Catching Sheep";
}