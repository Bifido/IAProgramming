#include "DogBehaviour\StateCatchingSheep.h"
#include "DogBehaviour\DogFSMCore.h"
#include "DogBehaviour\DogAgent.h"
#include "SheepBehaviour\SheepAgent.h"

#include "PassiveObj\Fence.h"

#include <assert.h>
#include <iostream>

using namespace std;

int DogReachSheep(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int DogReachSheep(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + abs(velocity.x) * 10) >= pos2.x) && ((pos1.x - abs(velocity.x) * 10) <= pos2.x);
	if (toReturn){
		return ((pos1.y + abs(velocity.y) * 10) >= pos2.y) && ((pos1.y - abs(velocity.y) * 10) <= pos2.y);
	}
	return false;
}

StateCatchingSheep::StateCatchingSheep()
{
}
StateCatchingSheep::~StateCatchingSheep()
{}

void StateCatchingSheep::OnEnter(DogAgent& agent) const{
	//cout << " dog stateCatching sheep" << endl;

	sf::Vector2<float> target = agent.GetSheep()->GetPosition();
	agent.SetTarget(target);
	agent.GetSheep()->SetEscaping(true);
}

void StateCatchingSheep::OnExit(DogAgent& agent) const{
	agent.SetCatched(false);
}

void StateCatchingSheep::Update(DogAgent& agent, float dt) const {
	sf::Vector2<float> direction = (agent.GetTarget() - agent.GetPosition());
	float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction.x = direction.x / magnitude;
	direction.y = direction.y / magnitude;
	sf::Vector2<float> newPos = agent.GetPosition();
	newPos.x += direction.x * agent.GetVelocity().x;
	newPos.y += direction.y * agent.GetVelocity().y;
	agent.SetPosition(newPos);
}

FSMStates StateCatchingSheep::CheckTransition(DogAgent& agent) const
{

	if (!agent.HasCatch())
	{
		//Check if dog catched the Sheep
		if (agent.CanCatch()){
			agent.SetCatched(true);
			agent.GetSheep()->SetCatched(true);
		}
		sf::Vector2<float> target = agent.GetSheep()->GetPosition();
		agent.SetTarget(target);
		return DefaultDogFSMCore::States::CATCHING;
	}
	else
	{
		return DefaultDogFSMCore::States::SWAN;
	}
}


std::string StateCatchingSheep::GetStateName() const
{
	return "State Catching Sheep";
}