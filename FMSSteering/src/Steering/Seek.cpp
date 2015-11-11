#include "Steering\Seek.h"
#include "Agent.h"


void Seek::Update(float dt)
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

Seek::Seek(std::string name)
	: Steering(name)
{}