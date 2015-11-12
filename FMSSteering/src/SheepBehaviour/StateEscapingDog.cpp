#include "SheepBehaviour\StateEscapingDog.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include "Steering\Steering.h"

#include <assert.h>
#include <iostream>

using namespace std;

StateEscapingDog::StateEscapingDog()
{
}
StateEscapingDog::~StateEscapingDog()
{
}

void StateEscapingDog::OnEnter(SheepAgent& agent) const
{
	Steering* ptr = agent.SetCurrentSteering(SteeringFactory::Evade);

	ptr->Init(&agent);
}

void StateEscapingDog::OnExit(SheepAgent& agent) const
{
	agent.RemoveCurrentSteering();
}

void StateEscapingDog::Update(SheepAgent& agent, float dt) const
{
	sf::Vector2<float> target = agent.GetDog()->GetPosition();
	agent.SetTarget(target);

	if (agent.GetCurrentSteering() != nullptr)
	{
		agent.GetCurrentSteering()->Update(dt);

		// If position is on border or the actual position of the sheep is inside the fence, recalculate position
		sf::Vector2<float> newPos = agent.GetPosition();
		if (agent.GetFence()->IsPointInside(newPos) || newPos.x < 0 || newPos.x > 1 || newPos.y < 0 || newPos.y > 1)
		{
			target = agent.GetFence()->GetRandomPointOutside();
			agent.SetTarget(target);

			agent.GetCurrentSteering()->Update(dt);
		}
	}
}

FSMStates StateEscapingDog::CheckTransition(SheepAgent& agent) const
{
	if (agent.IsCatched())
	{
		return DefaultSheepFSMCore::States::BACK_IN_FENCE;
	}
	else
	{
		//Check if dog catched the Sheep		
		sf::Vector2<float> target = agent.GetDog()->GetPosition();
		agent.SetTarget(target);
		return DefaultSheepFSMCore::States::ESCAPE_FROM_DOG;
	}
}

std::string StateEscapingDog::GetStateName() const
{
	return "StateEscapingDog";
}