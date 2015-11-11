#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include "Steering\Seek.h"
#include "Steering\Arrive.h"

#include <assert.h>
#include <iostream>

WalkNano::WalkNano()
{}
WalkNano::~WalkNano()
{}

void WalkNano::OnEnter(NanoAgent& agent) const{
	//agent.SetCurrentSteering(new Seek("NanoSeek", &agent));
	agent.SetCurrentSteering(new Arrive("NanoSeek", &agent, 0.03f, 0.00002f));
}

void WalkNano::OnExit(NanoAgent& agent) const{

	agent.SetVelocity(sf::Vector2<float>(0, 0));
	//Seek* steering = (Seek*)agent.RemoveCurrentSteering();
	Arrive* steering = (Arrive*)agent.RemoveCurrentSteering();
	delete steering;
}

void WalkNano::Update(NanoAgent& agent, float dt) const {
	agent.GetCurrentSteering()->Upadate(dt);
}

FSMStates WalkNano::CheckTransition(NanoAgent& agent) const
{
	if (agent.GetMine() != nullptr && agent.GetTarget() == agent.GetMine()->GetPosition() && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetMine()->GetPosition(), agent.GetVelocity())){
		return DefaultNanoFSMCore::States::MINE;
	}
	else if (agent.GetHome() != nullptr && agent.GetTarget() == agent.GetHome()->GetPosition() && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetHome()->GetPosition(), agent.GetVelocity())){
		return DefaultNanoFSMCore::States::HOME;
	}
	return DefaultNanoFSMCore::States::WALK;
}

std::string WalkNano::GetStateName() const
{
	return "WalkNano";
}