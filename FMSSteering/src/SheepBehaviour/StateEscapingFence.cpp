#include "SheepBehaviour\StateEscapingFence.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include <assert.h>
#include <iostream>

using namespace std;

int HasReachTarget3(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int HasReachTarget3(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + abs(velocity.x) * 10) >= pos2.x) && ((pos1.x - abs(velocity.x) * 10) <= pos2.x);
	if (toReturn){
		return ((pos1.y + abs(velocity.y) * 10) >= pos2.y) && ((pos1.y - abs(velocity.y) * 10) <= pos2.y);
	}
	return false;
}

StateEscapingFence::StateEscapingFence()
{
}
StateEscapingFence::~StateEscapingFence()
{}

void StateEscapingFence::OnEnter(SheepAgent& agent) const{
	agent.SetInFence(false);
	sf::Vector2<float> target = agent.GetFence()->GetEscapingPoint();
	agent.SetTarget(target);
}

void StateEscapingFence::OnExit(SheepAgent& agent) const{
	//agent.SetVelocity(sf::Vector2<float>(0, 0));
}

void StateEscapingFence::Update(SheepAgent& agent) const {
	sf::Vector2<float> direction = (agent.GetTarget() - agent.GetPosition());
	float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	sf::Vector2<float> newPos = agent.GetPosition();
	newPos.x += direction.x * agent.GetVelocity().x;
	newPos.y += direction.y * agent.GetVelocity().y;
	agent.SetPosition(newPos);
}

FSMStates StateEscapingFence::CheckTransition(SheepAgent& agent) const
{
	if (!agent.IsEscaping()){
		if (HasReachTarget3(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity()))
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
		//TODO set escaping from dog state
		return DefaultSheepFSMCore::States::BRUCA;
	}
}