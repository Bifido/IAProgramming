#include "SheepBehaviour\StateBruca.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include "Steering\Steering.h"

#include <assert.h>
#include <iostream>

using namespace std;

StateBruca::StateBruca()
{
}
StateBruca::~StateBruca()
{}

void StateBruca::OnEnter(SheepAgent& agent) const
{
	Steering* ptr = agent.SetCurrentSteering(SteeringFactory::Seek);

	sf::Vector2<float> target = agent.GetFence()->GetRandomPointInside();
	agent.SetTarget(target);

	ptr->Init(&agent);
}

void StateBruca::OnExit(SheepAgent& agent) const
{
	agent.RemoveCurrentSteering();
}

void StateBruca::Update(SheepAgent& agent, float dt) const 
{
	if (agent.GetCurrentSteering() != nullptr)
	{
		agent.GetCurrentSteering()->Update(dt);
	}
}

FSMStates StateBruca::CheckTransition(SheepAgent& agent) const
{
	//inside Fence
	if (agent.IsInFence()){
		if (agent.GetCurrentSteering() != nullptr && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity())){
			float randomNumber = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (randomNumber < 0.8f){
				sf::Vector2<float> target = agent.GetFence()->GetRandomPointInside();
				agent.SetTarget(target);
			}
			else{
				sf::Vector2<float> target = agent.GetFence()->GetEscapingPoint();
				agent.SetTarget(target);
				return DefaultSheepFSMCore::States::ESCAPING_FENCE;
			}
		}
	}
	//outside fence
	else{
		//Don't need to check if is catched because is catchable only by dog when the sheep isn't in the fence
		//sheep must pass in ESCAPRE_FROM_DOG
		if (agent.IsEscaping())
		{
			sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
			agent.SetTarget(target);
			return DefaultSheepFSMCore::States::ESCAPE_FROM_DOG;
		}
		else
		{
			if (agent.GetCurrentSteering() != nullptr && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity()))
			{
				sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
				agent.SetTarget(target);
			}
		}
	}
	return DefaultSheepFSMCore::States::BRUCA;
}

std::string StateBruca::GetStateName() const
{
	return "StateBruca";
}