#include "SheepBehaviour\StateEscapingFence.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include "Steering\Steering.h"

#include <assert.h>
#include <iostream>

using namespace std;

StateEscapingFence::StateEscapingFence()
{
}
StateEscapingFence::~StateEscapingFence()
{}

void StateEscapingFence::OnEnter(SheepAgent& agent) const
{
	Steering* ptr = agent.SetCurrentSteering(SteeringFactory::Seek);
	
	sf::Vector2<float> target = agent.GetFence()->GetEscapingPoint();
	agent.SetTarget(target);

	ptr->Init(&agent);
}

void StateEscapingFence::OnExit(SheepAgent& agent) const
{
	agent.RemoveCurrentSteering();
	agent.SetInFence(false);
}

void StateEscapingFence::Update(SheepAgent& agent, float dt) const 
{
	if (agent.GetCurrentSteering() != nullptr)
	{
		agent.GetCurrentSteering()->Update(dt);
	}
}

FSMStates StateEscapingFence::CheckTransition(SheepAgent& agent) const
{
	if (!agent.IsEscaping()){
		if (agent.GetCurrentSteering() != nullptr && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity()))
		{
			sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
			agent.SetTarget(target);
			return DefaultSheepFSMCore::States::BRUCA;
		}
		else
		{
			sf::Vector2<float> target = agent.GetFence()->GetEscapingPoint();
			agent.SetTarget(target);
			return DefaultSheepFSMCore::States::ESCAPING_FENCE;
		}
	}
	else
	{
		return DefaultSheepFSMCore::States::ESCAPE_FROM_DOG;
	}
}

std::string StateEscapingFence::GetStateName() const
{
	return "StateEscapingFence";
}