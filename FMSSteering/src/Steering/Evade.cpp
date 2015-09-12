#include "Steering\Evade.h"
#include "Agent.h"


void Evade::Upadate(float dt)
{
	sf::Vector2<float> result;
	SteerAway(m_parent->GetTarget(), result);

	m_parent->SetPosition(m_parent->GetPosition() + result);
}

void Evade::Reset()
{

}

void Evade::Draw()
{

}

Evade::Evade(std::string name, Agent* partent)
	: Steering(name, partent)
{}