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
	agent.SetVelocity((agent.GetTarget() - agent.GetPosition() + sf::Vector2<float>(-0.1f, 0.f)) * 0.0001f);
}

void WalkNanoLeft::OnExit(NanoAgent& agent) const{

	agent.SetVelocity(sf::Vector2<float>(0, 0));
}

void WalkNanoLeft::Update(NanoAgent& agent) const {

	sf::Vector2<float> vel = agent.GetVelocity(); // NOTA: the velocities must be in the order of 0.001 ~ 0.0001
	agent.SetPosition(agent.GetPosition() + vel);
}

FSMStates WalkNanoLeft::CheckTransition(NanoAgent& agent) const
{
	return FSMCore<NanoAgent, 1>::States::RIGHT;
}