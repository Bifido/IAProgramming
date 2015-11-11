#include "DogBehaviour\StateSwan.h"
#include "DogBehaviour\DogFSMCore.h"
#include "DogBehaviour\DogAgent.h"

#include "PassiveObj\Fence.h"

#include <assert.h>
#include <iostream>

using namespace std;

int DogReachSwan(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int DogReachSwan(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + abs(velocity.x) * 10) >= pos2.x) && ((pos1.x - abs(velocity.x) * 10) <= pos2.x);
	if (toReturn){
		return ((pos1.y + abs(velocity.y) * 10) >= pos2.y) && ((pos1.y - abs(velocity.y) * 10) <= pos2.y);
	}
	return false;
}

StateSwan::StateSwan()
{
}
StateSwan::~StateSwan()
{}

void StateSwan::OnEnter(DogAgent& agent) const{
	//cout << " dog stateSwan" << endl;

	sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
	agent.SetTarget(target);
}

void StateSwan::OnExit(DogAgent& agent) const{
}

void StateSwan::Update(DogAgent& agent) const {
	sf::Vector2<float> direction = (agent.GetTarget() - agent.GetPosition());
	float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	sf::Vector2<float> newPos = agent.GetPosition();
	newPos.x += direction.x * agent.GetVelocity().x;
	newPos.y += direction.y * agent.GetVelocity().y;
	agent.SetPosition(newPos);
}

FSMStates StateSwan::CheckTransition(DogAgent& agent) const
{
	if (agent.CanStartCatching() && !agent.HasCatch())
	{
		//Check if dog can start to catch Sheep
		agent.SetCatching(true);
		return DefaultDogFSMCore::States::CATCHING;
	}
	if (DogReachSwan(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity()))
	{
		sf::Vector2<float> target = agent.GetFence()->GetRandomPointOutside();
		agent.SetTarget(target);
		return DefaultDogFSMCore::States::SWAN;
	}
}