#include "SheepBehaviour\StateEscapingDog.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include <assert.h>
#include <iostream>

using namespace std;

int HasReachTarget4(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int HasReachTarget4(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + abs(velocity.x) * 10) >= pos2.x) && ((pos1.x - abs(velocity.x) * 10) <= pos2.x);
	if (toReturn){
		return ((pos1.y + abs(velocity.y) * 10) >= pos2.y) && ((pos1.y - abs(velocity.y) * 10) <= pos2.y);
	}
	return false;
}

StateEscapingDog::StateEscapingDog()
{
}
StateEscapingDog::~StateEscapingDog()
{
}

void StateEscapingDog::OnEnter(SheepAgent& agent) const
{
}

void StateEscapingDog::OnExit(SheepAgent& agent) const
{
}

void StateEscapingDog::Update(SheepAgent& agent) const
{
	//TODO VALE:check if IsCatched
	if (agent.IsCatched()){
		sf::Vector2<float> target = agent.GetFence()->GetEscapingPoint();
		agent.SetTarget(target);

		sf::Vector2<float> direction = (agent.GetTarget() - agent.GetPosition());
		float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
		direction.x = direction.x / magnitude;
		direction.y = direction.y / magnitude;
		sf::Vector2<float> newPos = agent.GetPosition();
		newPos.x += direction.x * agent.GetVelocity().x;
		newPos.y += direction.y * agent.GetVelocity().y;
		agent.SetPosition(newPos);
	}
	else
	{
		//TODO VALE:actually get a random point outside fence, then it will be the dog position
		sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
		agent.SetTarget(target);

		sf::Vector2<float> direction = (agent.GetTarget() - agent.GetPosition());
		float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
		direction.x = direction.x / magnitude;
		direction.y = direction.y / magnitude;
		sf::Vector2<float> newPos = agent.GetPosition();
		newPos.x += direction.x * agent.GetVelocity().x;
		newPos.y += direction.y * agent.GetVelocity().y;
		agent.SetPosition(newPos);

		//TODO VALE: when target will be dog position
		/*sf::Vector2<float> direction = (agent.GetPosition() - agent.GetTarget());
		float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
		direction.x = direction.x / magnitude;
		direction.y = direction.y / magnitude;
		sf::Vector2<float> newPos = agent.GetPosition();
		newPos.x += direction.x * agent.GetVelocity().x;
		newPos.y += direction.y * agent.GetVelocity().y;
		agent.SetPosition(newPos);*/
	}
}

FSMStates StateEscapingDog::CheckTransition(SheepAgent& agent) const
{
	if (agent.IsCatched())
	{
		DefaultSheepFSMCore::States::BACK_IN_FENCE;
	}
	else{
		return DefaultSheepFSMCore::States::ESCAPE_FROM_DOG;
	}
}