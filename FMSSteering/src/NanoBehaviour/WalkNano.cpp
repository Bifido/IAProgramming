#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include <assert.h>
#include <iostream>

int HasReachTarget(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

WalkNano::WalkNano()
{}
WalkNano::~WalkNano()
{}

void WalkNano::OnEnter(NanoAgent& agent) const{
	agent.SetVelocity( (agent.GetTarget() - agent.GetPosition()) * 0.001f );
}

void WalkNano::OnExit(NanoAgent& agent) const{

	agent.SetVelocity(sf::Vector2<float>(0, 0));
}

void WalkNano::Update(NanoAgent& agent) const {
	
	sf::Vector2<float> vel = agent.GetVelocity(); // NOTA: the velocities must be in the order of 0.001 ~ 0.0001
	agent.SetPosition(agent.GetPosition() + vel);
}

FSMStates WalkNano::CheckTransition(NanoAgent& agent) const
{
	if (agent.GetMine() != nullptr && HasReachTarget(agent.GetPosition(), agent.GetMine()->GetPosition(), agent.GetVelocity()) ){ 
		return FSMCore<NanoAgent>::States::MINE;
	}
	else if (agent.GetHome() != nullptr && HasReachTarget(agent.GetPosition(), agent.GetHome()->GetPosition(), agent.GetVelocity())){
		return FSMCore<NanoAgent>::States::HOME;
	}
	return FSMCore<NanoAgent>::States::WALK;
}

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int HasReachTarget(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + abs(velocity.x) * 10) >= pos2.x) && ((pos1.x - abs(velocity.x) * 10) <= pos2.x);
	if (toReturn){
		return ((pos1.y + abs(velocity.y) * 10) >= pos2.y) && ((pos1.y - abs(velocity.y) * 10) <= pos2.y);
	}
	return false;
}