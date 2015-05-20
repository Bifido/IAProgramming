#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include <assert.h>

WalkNano::WalkNano()
	: State(FSMCore < NanoAgent > ::GetInstance())
{}
WalkNano::~WalkNano()
{}

void WalkNano::OnEnter(NanoAgent* agent) const{
	//TODO: Remove from here the decision of Agent velocity
	assert(agent != nullptr);

	agent->SetVelocity( agent->GetTarget() * 0.0001f );
}

void WalkNano::OnExit(NanoAgent* agent) const{
	assert(agent != nullptr);

	agent->SetVelocity(sf::Vector2<float>(0, 0));
}

void WalkNano::Update(NanoAgent* agent) const {
	assert(agent != nullptr);
	
	sf::Vector2<float> vel = agent->GetVelocity(); // NOTA: the velocities must be in the order of 0.001 ~ 0.0001
	agent->SetPosition(agent->GetPosition() + vel);
}

State<NanoAgent>* WalkNano::CheckTransition(NanoAgent* agent) const
{
	assert(agent != nullptr);

	if (agent->GetPosition() == agent->GetMine()->GetPosition()){ // TODO: add tollerance (with this velocity caluculations, it isn't needed)
		return m_fsmCore.GetState(FSMCore<NanoAgent>::MINE);
	}
	else if (agent->GetPosition() == agent->GetHome()->GetPosition()){ // TODO: add tollerance (with this velocity caluculations, it isn't needed)
		return m_fsmCore.GetState(FSMCore<NanoAgent>::HOME);
	}
	return m_fsmCore.GetState(FSMCore<NanoAgent>::WALK);
}