#include "SheepBehaviour\StateBruca.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include <assert.h>
#include <iostream>

using namespace std;

int HasReachTarget2(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int HasReachTarget2(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + abs(velocity.x) * 10) >= pos2.x) && ((pos1.x - abs(velocity.x) * 10) <= pos2.x);
	if (toReturn){
		return ((pos1.y + abs(velocity.y) * 10) >= pos2.y) && ((pos1.y - abs(velocity.y) * 10) <= pos2.y);
	}
	return false;
}

StateBruca::StateBruca()
{
}
StateBruca::~StateBruca()
{}

void StateBruca::OnEnter(SheepAgent& agent) const{
	sf::Vector2<float> target = agent.GetFence()->GetRandomPointInside();
	agent.SetTarget(target);
}

void StateBruca::OnExit(SheepAgent& agent) const{
}

void StateBruca::Update(SheepAgent& agent, float dt) const {
	sf::Vector2<float> direction = (agent.GetTarget() - agent.GetPosition());
	float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	sf::Vector2<float> newPos = agent.GetPosition();
	newPos.x += direction.x * agent.GetVelocity().x;
	newPos.y += direction.y * agent.GetVelocity().y;
	agent.SetPosition(newPos);

}

FSMStates StateBruca::CheckTransition(SheepAgent& agent) const
{
	if (agent.IsInFence()){
		if (HasReachTarget2(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity())){			
			float randomNumber = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (randomNumber < 0.8f){
				sf::Vector2<float> target = agent.GetFence()->GetRandomPointInside();
				agent.SetTarget(target);
				return DefaultSheepFSMCore::States::BRUCA;
			}
			else{
				sf::Vector2<float> target = agent.GetFence()->GetEscapingPoint();
				agent.SetTarget(target);
				return DefaultSheepFSMCore::States::ESCAPING_FENCE;
			}
		}
	}
	else{

		//Don't need to check if is catched because is catchable only by dog when the sheep isn't in the fence
		//sheep must pass in ESCAPRE_FROM_DOG
		if (agent.IsEscaping())
		{
			//TODO VALE: when dogs set's sheep IsEscaping(true) can get directly the dog's position as target to check it as valid
			//inside StateEscapingDog.Update();
			sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
			agent.SetTarget(target);
			return DefaultSheepFSMCore::States::ESCAPE_FROM_DOG;
		}
		else
		{
			if (HasReachTarget2(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity()))
			{
				sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
				agent.SetTarget(target);
			}
			return DefaultSheepFSMCore::States::BRUCA;
		}
	}
}

std::string StateBruca::GetStateName() const
{
	return "StateBruca";
}