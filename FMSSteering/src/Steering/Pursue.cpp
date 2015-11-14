#include "Steering\Pursue.h"
#include "Agent.h"


void Pursue::Update(float dt)
{
	sf::Vector2<float> result;
	sf::Vector2<float> predictionPoint = m_parent->GetTarget() + m_parent->GetTargetVelocity()*K_NUMBER_OF_PREDICTION_FRAME;

	SteerTowards(predictionPoint, result);

	m_parent->SetPosition(m_parent->GetPosition() + result);
}

void Pursue::Reset()
{

}

void Pursue::Draw()
{

}

Pursue::Pursue(std::string name)
	: Steering(name)
{}