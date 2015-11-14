#include "Steering\Wander.h"
#include "Agent.h"
#include <math.h>


void Wander::Update(float dt)
{
	sf::Vector2<float> wanderRes = CalculateWander();
	wanderRes = wanderRes + m_parent->GetVelocity();
	m_parent->SetPosition(m_parent->GetPosition() + wanderRes);
}

void Wander::Reset()
{

}

void Wander::Draw()
{

}

Wander::Wander(std::string name): 
	Steering(name), 
	m_fWanderAngle(30.0f)
{}

sf::Vector2<float> Wander::CalculateWander()
{
	sf::Vector2<float> circleCenter;
	circleCenter = m_parent->GetVelocity();
	circleCenter = Normailize(circleCenter)*K_CIRCLE_DISTANCE;

	// Calculate the displacement force
	sf::Vector2<float> displacement(0.0f, -1.0f);
	displacement *= K_CIRCLE_RADIUS;

	// Randomly change the vector direction
	// by making it change its current angle
	float len = Vector2LenghtSq(displacement);
	displacement.x = cos(m_fWanderAngle) * len;
	displacement.y = sin(m_fWanderAngle) * len;
	//
	// Change wanderAngle just a bit, so it
	// won't have the same value in the
	// next game frame.
	m_fWanderAngle += rand() * K_MAX_ANGLE - K_MAX_ANGLE * .5;

	return circleCenter + displacement;
}