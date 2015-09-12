#include "SheepBehaviour\StateBackToFence.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include <assert.h>
#include <iostream>

using namespace std;

int HasReachTarget5(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int HasReachTarget5(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + abs(velocity.x) * 10) >= pos2.x) && ((pos1.x - abs(velocity.x) * 10) <= pos2.x);
	if (toReturn){
		return ((pos1.y + abs(velocity.y) * 10) >= pos2.y) && ((pos1.y - abs(velocity.y) * 10) <= pos2.y);
	}
	return false;
}

StateBackToFence::StateBackToFence()
{
}
StateBackToFence::~StateBackToFence()
{
}

void StateBackToFence::OnEnter(SheepAgent& agent) const
{
}

void StateBackToFence::OnExit(SheepAgent& agent) const
{
	agent.SetInFence(true);
	agent.SetEscaping(false);
	//being in fence, catched will be false
	agent.SetCatched();
}

void StateBackToFence::Update(SheepAgent& agent) const
{
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

FSMStates StateBackToFence::CheckTransition(SheepAgent& agent) const
{
	if (HasReachTarget5(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity()))
	{
		return DefaultSheepFSMCore::States::BRUCA;
	}
	else{
		return DefaultSheepFSMCore::States::BACK_IN_FENCE;
	}
}