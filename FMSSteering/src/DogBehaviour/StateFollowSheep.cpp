#include "DogBehaviour\StateFollowSheep.h"
#include "DogBehaviour\DogFSMCore.h"
#include "DogBehaviour\DogAgent.h"
#include "SheepBehaviour\SheepAgent.h"

#include "Steering\Steering.h"

using namespace std;

StateFollowSheep::StateFollowSheep()
{
}
StateFollowSheep::~StateFollowSheep()
{}

void StateFollowSheep::OnEnter(DogAgent& agent) const{
	Steering* ptr = agent.SetCurrentSteering(SteeringFactory::Seek);

	ptr->Init(&agent);
}

void StateFollowSheep::OnExit(DogAgent& agent) const{
}

void StateFollowSheep::Update(DogAgent& agent, float dt) const {

	agent.SetTarget(agent.GetSheep()->GetPosition());

	if (agent.GetCurrentSteering() != nullptr)
	{
		agent.GetCurrentSteering()->Update(dt);
	}
}

FSMStates StateFollowSheep::CheckTransition(DogAgent& agent) const
{
	if (agent.GetSheep()->IsInFence())
	{
		return DefaultDogFSMCore::States::SWAN;
	}
	else
	{
		return DefaultDogFSMCore::States::FOLLOWING_SHEEP;
	}
}

std::string StateFollowSheep::GetStateName() const
{
	return "State Follow Sheep";
}