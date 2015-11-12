#include "SheepBehaviour\StateBackToFence.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include "Steering\Steering.h"

#include <assert.h>
#include <iostream>

using namespace std;

StateBackToFence::StateBackToFence()
{
}
StateBackToFence::~StateBackToFence()
{
}

void StateBackToFence::OnEnter(SheepAgent& agent) const
{
	Steering* ptr = agent.SetCurrentSteering(SteeringFactory::Seek);

	ptr->Init(&agent);
}

void StateBackToFence::OnExit(SheepAgent& agent) const
{
	agent.RemoveCurrentSteering();
	agent.SetInFence(true);
	agent.SetEscaping(false);
	agent.SetCatched(false);
	agent.GetDog()->SetCatched(false);
	//being in fence, catched will be false
}

void StateBackToFence::Update(SheepAgent& agent, float dt) const
{
	sf::Vector2<float> target = agent.GetFence()->GetEscapingPoint();
	agent.SetTarget(target);

	if (agent.GetCurrentSteering() != nullptr)
	{
		agent.GetCurrentSteering()->Update(dt);
	}
}

FSMStates StateBackToFence::CheckTransition(SheepAgent& agent) const
{
	if (agent.GetCurrentSteering() != nullptr && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity()))
	{
		return DefaultSheepFSMCore::States::BRUCA;
	}
	else{
		return DefaultSheepFSMCore::States::BACK_IN_FENCE;
	}
}

std::string StateBackToFence::GetStateName() const
{
	return "StateBackToFence";
}