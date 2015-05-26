#include "NanoBehaviour\WalkNanoRight.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include <assert.h>
#include <iostream>

int HasReachTarget2(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

WalkNanoRight::WalkNanoRight()
{}
WalkNanoRight::~WalkNanoRight()
{}

void WalkNanoRight::OnEnter(NanoAgent& agent) const{
	agent.SetVelocity((agent.GetTarget() - agent.GetPosition() + sf::Vector2<float>(0.f,0.1f)) * 0.0001f);
}

void WalkNanoRight::OnExit(NanoAgent& agent) const{

	agent.SetVelocity(sf::Vector2<float>(0, 0));
}

void WalkNanoRight::Update(NanoAgent& agent) const {

	sf::Vector2<float> vel = agent.GetVelocity(); // NOTA: the velocities must be in the order of 0.001 ~ 0.0001
	agent.SetPosition(agent.GetPosition() + vel);
}

FSMStates WalkNanoRight::CheckTransition(NanoAgent& agent) const
{
	return FSMCore<NanoAgent, 1>::States::LEFT;
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