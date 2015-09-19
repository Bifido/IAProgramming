#include "Steering\Seek.h"
#include "Agent.h"


void Seek::Upadate(float dt)
{
	sf::Vector2<float> result;
	SteerTowards(m_parent->GetTarget(), result);

	m_parent->SetPosition(m_parent->GetPosition() + result);
}

void Seek::Reset()
{

}

void Seek::Draw()
{

}

Seek::Seek(std::string name, Agent* partent)
	: Steering(name,partent)
{}