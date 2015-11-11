#include "DogBehaviour\StateSwan.h"
#include "DogBehaviour\DogFSMCore.h"
#include "DogBehaviour\DogAgent.h"

#include "PassiveObj\Fence.h"

#include "Steering\Steering.h"

#include <assert.h>
#include <iostream>

using namespace std;

StateSwan::StateSwan()
{
}
StateSwan::~StateSwan()
{}

void StateSwan::OnEnter(DogAgent& agent) const{
	Steering* ptr = agent.SetCurrentSteering(SteeringFactory::Seek);

	sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
	agent.SetTarget(target);

	ptr->Init(&agent);
}

void StateSwan::OnExit(DogAgent& agent) const{
}

void StateSwan::Update(DogAgent& agent, float dt) const {
	
	if (agent.GetCurrentSteering() != nullptr)
	{
		agent.GetCurrentSteering()->Update(dt);
	}
}

FSMStates StateSwan::CheckTransition(DogAgent& agent) const
{
	if (agent.CanStartCatching() && !agent.HasCatch())
	{
		//Check if dog can start to catch Sheep
		agent.SetCatching(true);
		return DefaultDogFSMCore::States::CATCHING;
	}
	if (agent.GetCurrentSteering() != nullptr && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity()))
	{
		sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
		agent.SetTarget(target);
		return DefaultDogFSMCore::States::SWAN;
	}
}

std::string StateSwan::GetStateName() const
{
	return "State Swan";
}