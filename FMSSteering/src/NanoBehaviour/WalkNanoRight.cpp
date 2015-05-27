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

void WalkNanoRight::OnEnter(NanoAgent& agent) const
{
}

void WalkNanoRight::OnExit(NanoAgent& agent) const
{
}

void WalkNanoRight::Update(NanoAgent& agent) const 
{
	//agent.DecrementStamina(agent.STAMINA_USAGE);
	sf::Vector2<float> vel = agent.GetVelocity(); // NOTA: the velocities must be in the order of 0.001 ~ 0.0001
	agent.SetPosition(agent.GetPosition() + vel);
	
}

FSMStates WalkNanoRight::CheckTransition(NanoAgent& agent) const
{
	return SubWalkNanoFSMCore::States::LEFT;
}