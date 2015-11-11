#include <assert.h>
#include "Agent.h"
#include "Steering\Steering.h"

using namespace sf;

Agent::Agent(std::string name) :
m_name(name),
m_pos(Vector2<float>(0, 0)),
m_velocity(Vector2<float>(0, 0)),
m_viewInfo(nullptr)
{
}


const Vector2<float>& Agent::GetPosition() const{
	return m_pos;
}

const Vector2<float>& Agent::GetVelocity() const{
	return m_velocity;
}

const sf::Vector2<float>& Agent::GetTarget() const{
	return m_target;
}

float Agent::GetMaxSpeed() const
{
	return m_maxSpeed;
}

Steering* Agent::GetCurrentSteering() const
{
	return m_currentSteering;
}

ViewComponent* Agent::GetViewComponent() const{
	return m_viewInfo;
}

void Agent::SetPosition(const Vector2<float>& newPosition){
	// The position must be expressed in term of numbers between 0 and 1
	assert(newPosition.x <= 1 && newPosition.x >= 0 && newPosition.y <= 1 && newPosition.y >= 0);

	m_pos = newPosition;
}

void Agent::SetVelocity(const Vector2<float>& newVelocity){
	m_velocity = newVelocity;
}

void Agent::SetTarget(const sf::Vector2<float>& newTarget){
	m_target = newTarget;
}

void Agent::SetMaxSpeed(float maxSpeed)
{
	m_maxSpeed = maxSpeed;
}

Steering* Agent::SetCurrentSteering(SteeringFactory::SteeringType _steeringType)
{
	Steering* pointer = SteeringFactory::BuildSteering(_steeringType);
	m_currentSteering = pointer;
	return pointer;
}

void Agent::SetViewComponent(ViewComponent* viewComp){
	m_viewInfo = viewComp;
}

Agent::~Agent(){ }

Steering* Agent::RemoveCurrentSteering()
{
	Steering* temp = m_currentSteering;
	if (m_currentSteering != nullptr)
	{
		m_currentSteering->Uninit();
		delete m_currentSteering;
		m_currentSteering = nullptr;
	}
	return temp;
}

std::string Agent::GetName()
{
	return m_name;
}