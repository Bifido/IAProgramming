#include "SheepBehaviour\WalkSheep.h"
#include "SheepBehaviour\SheepFSMCore.h"
#include "SheepBehaviour\SheepAgent.h"

#include <assert.h>
#include <iostream>

int HasReachTarget2(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

WalkSheep::WalkSheep()
{}
WalkSheep::~WalkSheep()
{}

void WalkSheep::OnEnter(SheepAgent& agent) const{
	agent.SetVelocity((agent.GetTarget() - agent.GetPosition()) * 0.001f);
}

void WalkSheep::OnExit(SheepAgent& agent) const{

	agent.SetVelocity(sf::Vector2<float>(0, 0));
	agent.FSMRemove();
}

void WalkSheep::Update(SheepAgent& agent) const {

	sf::Vector2<float> vel = agent.GetVelocity(); // NOTA: the velocities must be in the order of 0.001 ~ 0.0001
	//agent.SetPosition(agent.GetPosition() + vel*0.1f);

}

FSMStates WalkSheep::CheckTransition(SheepAgent& agent) const
{
	/*if (agent.GetMine() != nullptr && agent.GetTarget() == agent.GetMine()->GetPosition() && HasReachTarget(agent.GetPosition(), agent.GetMine()->GetPosition(), agent.GetVelocity())){
		return DefaultNanoFSMCore::States::MINE;
	}
	else if (agent.GetHome() != nullptr && agent.GetTarget() == agent.GetHome()->GetPosition() && HasReachTarget(agent.GetPosition(), agent.GetHome()->GetPosition(), agent.GetVelocity())){
		return DefaultNanoFSMCore::States::HOME;
	}*/
	return DefaultSheepFSMCore::States::WALK;
}

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