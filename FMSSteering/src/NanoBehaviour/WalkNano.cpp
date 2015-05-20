#include "NanoBehaviour\WalkNano.h"
#include "NanoBehaviour\NanoFSMCore.h"
#include "NanoBehaviour\NanoAgent.h"

#include "PassiveObj\Mine.h"
#include "PassiveObj\Home.h"

#include <assert.h>

int HasReachTarget(const sf::Vector2<float>&, const sf::Vector2<float>&, const sf::Vector2<float>&);

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

	if (agent->GetMine() != nullptr && HasReachTarget(agent->GetPosition(), agent->GetMine()->GetPosition(), agent->GetVelocity()) ){ 
		return m_fsmCore.GetState(FSMCore<NanoAgent>::MINE);
	}
	else if (agent->GetHome() != nullptr && HasReachTarget(agent->GetPosition(), agent->GetHome()->GetPosition(), agent->GetVelocity())){
		return m_fsmCore.GetState(FSMCore<NanoAgent>::HOME);
	}
	return m_fsmCore.GetState(FSMCore<NanoAgent>::WALK);
}

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int HasReachTarget(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + velocity.x) >= pos2.x) && ((pos1.x - velocity.x) <= pos2.x);
	if (toReturn){
		return ((pos1.y + velocity.y) >= pos2.y) && ((pos1.y - velocity.y) <= pos2.y);
	}
	return false;
}