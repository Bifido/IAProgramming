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
	//TODO SET Target
	sf::Vector2<float> target = agent.GetFence()->GetRandomPointInside();
	agent.SetTarget(target);
}

void StateBruca::OnExit(SheepAgent& agent) const{
	agent.SetVelocity(sf::Vector2<float>(0, 0));
}

void StateBruca::Update(SheepAgent& agent) const {
	cout << "Sheep Pos" << agent.GetPosition().x << " " << agent.GetPosition().y << endl;
	sf::Vector2<float> direction = (agent.GetTarget() - agent.GetPosition());
	sf::Vector2<float> newPos = agent.GetPosition();
	newPos.x += direction.x * agent.GetVelocity().x;
	newPos.y += direction.y * agent.GetVelocity().y;
	agent.SetPosition(newPos);
	cout << "Sheep new Pos" << newPos.x << " " << newPos.y << endl;

}

FSMStates StateBruca::CheckTransition(SheepAgent& agent) const
{
	/*if (agent.GetMine() != nullptr && agent.GetTarget() == agent.GetMine()->GetPosition() && HasReachTarget(agent.GetPosition(), agent.GetMine()->GetPosition(), agent.GetVelocity())){
	return DefaultNanoFSMCore::States::MINE;
	}
	else if (agent.GetHome() != nullptr && agent.GetTarget() == agent.GetHome()->GetPosition() && HasReachTarget(agent.GetPosition(), agent.GetHome()->GetPosition(), agent.GetVelocity())){
	return DefaultNanoFSMCore::States::HOME;
	}*/

	cout << "Sheep Walk CheckTrans" << endl;
	cout << "Sheep Target" << agent.GetTarget().x << " " << agent.GetTarget().y << endl;
	if (agent.IsEscaping()){
		//TODO substitute under with this return DefaultSheepFSMCore::States::ESCAPING_DOG;
		return DefaultSheepFSMCore::States::BRUCA;
	}
	else{
		if (agent.IsInFence()){
			if (HasReachTarget2(agent.GetPosition(), agent.GetTarget(), agent.GetVelocity())){
				cout << "Sheep reached target " << endl;
				return DefaultSheepFSMCore::States::BRUCA;
				//TODO random between
				/* se dentro, continuare a brucare oppure scappare dalla recinzione */
			}
		}
		else{
			return DefaultSheepFSMCore::States::BRUCA;
		}
	}
	return DefaultSheepFSMCore::States::BRUCA;
}