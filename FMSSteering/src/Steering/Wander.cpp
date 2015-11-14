#include "Steering\Wander.h"
#include "Agent.h"
#include <math.h>
#include <iostream>


void Wander::Update(float dt)
{
	sf::Vector2<float> wanderRes = CalculateWander();
	wanderRes = wanderRes + m_parent->GetVelocity();
	if (Vector2LenghtSq(wanderRes) > m_parent->GetMaxSpeed() * m_parent->GetMaxSpeed())
	{
		wanderRes = Normailize(wanderRes) * m_parent->GetMaxSpeed();
	}
	m_parent->SetVelocity(wanderRes);
	m_parent->SetPosition(m_parent->GetPosition() + wanderRes);
}

void Wander::Reset()
{

}

void Wander::Draw()
{

}

Wander::Wander(std::string name) :
Steering(name),
m_fWanderAngle(0.5f)
{}

sf::Vector2<float> Wander::CalculateWander()
{
	sf::Vector2<float> circleCenter;
	circleCenter = m_parent->GetVelocity();
	circleCenter = Normailize(circleCenter)*K_CIRCLE_DISTANCE;

	// Calculate the displacement force
	sf::Vector2<float> displacement;// Randomly change the vector direction
	// by making it change its current angle
	//float len = Vector2Lenght(displacement);
	displacement.x = cos(m_fWanderAngle) * K_CIRCLE_RADIUS;
	displacement.y = sin(m_fWanderAngle) * K_CIRCLE_RADIUS;

	// Change wanderAngle just a bit, so it
	// won't have the same value in the
	// next game frame.
	m_fWanderAngle += rand() / K_MAX_ANGLE - K_MAX_ANGLE * .5;

	return circleCenter + displacement;
}