#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include "Steering\Arrive.h"
#include "Steering\SteeringFactory.h"

#include <assert.h>
#include <iostream>

WalkNano::WalkNano()
{}
WalkNano::~WalkNano()
{}

void WalkNano::OnEnter(NanoAgent& agent) const{
	//agent.SetCurrentSteering(new Seek("NanoSeek", &agent));
	Arrive* ptr = dynamic_cast<Arrive*>(agent.SetCurrentSteering(SteeringFactory::SteeringType::Arrive));
	ptr->Init(&agent, 0.03f, 0.00002f);
}

void WalkNano::OnExit(NanoAgent& agent) const{

	agent.SetVelocity(sf::Vector2<float>(0, 0));
	agent.RemoveCurrentSteering();
}

void WalkNano::Update(NanoAgent& agent, float dt) const {
	agent.GetCurrentSteering()->Update(dt);
}

FSMStates WalkNano::CheckTransition(NanoAgent& agent) const
{
	if (agent.GetMine() != nullptr && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetMine()->GetPosition(), agent.GetVelocity())){
		return DefaultNanoFSMCore::States::MINE;
	}
	else if (agent.GetHome() != nullptr && agent.GetCurrentSteering()->HasReachTarget(agent.GetPosition(), agent.GetHome()->GetPosition(), agent.GetVelocity())){
		return DefaultNanoFSMCore::States::HOME;
	}
	return DefaultNanoFSMCore::States::WALK;
}

std::string WalkNano::GetStateName() const
{
	return "WalkNano";
}