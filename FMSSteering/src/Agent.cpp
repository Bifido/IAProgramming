#include <assert.h>
#include "Agent.h"

using namespace sf;

Agent::Agent() :
pos(Vector2<float>(0, 0)),
velocity(Vector2<float>(0, 0)),
viewInfo(nullptr)
{
}


const Vector2<float>& Agent::GetPosition() const{
	return pos;
}

const Vector2<float>& Agent::GetVelocity() const{
	return velocity;
}

const sf::Vector2<float>& Agent::GetTarget() const{
	return target;
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
	return viewInfo;
}

void Agent::SetPosition(const Vector2<float>& newPosition){
	// The position must be expressed in term of numbers between 0 and 1
	assert(newPosition.x <= 1 && newPosition.x >= 0 && newPosition.y <= 1 && newPosition.y >= 0);

	pos = newPosition;
}

void Agent::SetVelocity(const Vector2<float>& newVelocity){
	velocity = newVelocity;
}

void Agent::SetTarget(const sf::Vector2<float>& newTarget){
	target = newTarget;
}

void Agent::SetMaxSpeed(float maxSpeed)
{
	m_maxSpeed = maxSpeed;
}

void Agent::SetCurrentSteering(Steering* steering)
{
	m_currentSteering = steering;
}

void Agent::SetViewComponent(ViewComponent* viewComp){
	viewInfo = viewComp;
}

Agent::~Agent(){ }

Steering* Agent::RemoveCurrentSteering()
{
	Steering* temp = m_currentSteering;
	m_currentSteering = nullptr;
	return temp;
}