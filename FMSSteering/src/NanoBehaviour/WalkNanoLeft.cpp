#include "NanoBehaviour\WalkNanoLeft.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include <assert.h>
#include <iostream>


WalkNanoLeft::WalkNanoLeft()
{}
WalkNanoLeft::~WalkNanoLeft()
{}

void WalkNanoLeft::OnEnter(NanoAgent& agent) const{
	//agent.SetVelocity((agent.GetTarget() - agent.GetPosition()) * 0.0001f);
}

void WalkNanoLeft::OnExit(NanoAgent& agent) const{

	//agent.SetVelocity(sf::Vector2<float>(0, 0));
}

void WalkNanoLeft::Update(NanoAgent& agent) const 
{
	//agent.DecrementStamina(agent.STAMINA_USAGE);
	sf::Vector2<float> vel = agent.GetVelocity(); // NOTA: the velocities must be in the order of 0.001 ~ 0.0001
	agent.SetPosition(agent.GetPosition() + vel);
}

FSMStates WalkNanoLeft::CheckTransition(NanoAgent& agent) const
{
	return SubWalkNanoFSMCore::States::RIGHT;
}