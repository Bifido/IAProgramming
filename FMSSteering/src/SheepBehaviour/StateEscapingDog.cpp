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
	//cout << " sheep Escaping dog" << endl;
}

void StateEscapingDog::OnExit(SheepAgent& agent) const
{
}

void StateEscapingDog::Update(SheepAgent& agent) const
{
	sf::Vector2<float> target = agent.GetDog()->GetPosition();
	agent.SetTarget(target);

	sf::Vector2<float> direction = (agent.GetPosition() - agent.GetTarget());
	float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	sf::Vector2<float> newPos = agent.GetPosition();
	newPos.x += direction.x * agent.GetVelocity().x;
	newPos.y += direction.y * agent.GetVelocity().y;
	if (agent.GetFence()->IsPointInside(newPos) || newPos.x < 0 || newPos.x > 1 || newPos.y < 0 || newPos.y > 1)
	{
		target = agent.GetFence()->GetRandomPointOutside();
		agent.SetTarget(target);

		direction = (agent.GetPosition() - agent.GetTarget());
		magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
		direction.x = direction.x / magnitude;
		direction.y = direction.y / magnitude;
		newPos = agent.GetPosition();
		newPos.x += direction.x * agent.GetVelocity().x;
		newPos.y += direction.y * agent.GetVelocity().y;	
		
		if (newPos.x < 0)
			newPos.x = 0.1f;
		if (newPos.x > 1)
			newPos.x = 0.99f;
		if (newPos.y < 0)
			newPos.y = 0.1f;
		if (newPos.y > 1)
			newPos.y = 0.99f;
	}
	agent.SetPosition(newPos);
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