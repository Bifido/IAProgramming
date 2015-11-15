#include "Steering\Arrive.h"
#include "Agent.h"
#include <iostream>


void Arrive::Update(float dt)
{
	sf::Vector2<float> result;
	SteerArrive(m_parent->GetTarget(), result);

	m_parent->SetPosition(m_parent->GetPosition() + result);
}

void Arrive::Reset()
{

}

void Arrive::Draw()
{

}


Arrive::Arrive(std::string name):
	Steering(name)
{
}

void Arrive::Init(Agent* partent, float arriveDistance, float minSpeed)
{
	m_parent = partent;
	m_arriveDistance = arriveDistance;
	m_minSpeed = minSpeed;
}

void Arrive::SteerArrive(const sf::Vector2<float>& target, sf::Vector2<float>& result)
{
	sf::Vector2<float> desired = target - m_parent->GetPosition();
	float targetDistance = Vector2LenghtSq(desired);
	if (targetDistance > 0)
	{
		float speed;
		if (targetDistance < m_arriveDistance)
		{
			speed = m_parent->GetMaxSpeed() * (targetDistance / m_arriveDistance);
			speed = fmax(speed, m_minSpeed);
		}
		else
		{
			speed = m_parent->GetMaxSpeed();
		}
		desired = Normailize(desired) * speed;
		result = desired - m_parent->GetVelocity();
	}
	else
	{
		result.x = 0.0f;
		result.y = 0.0f;
	}
}