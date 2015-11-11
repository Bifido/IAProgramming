#include "Steering\Steering.h"
#include "Agent.h"
#include <iostream>

void Steering::Update(float dt)
{}
void Steering::Reset()
{}
void Steering::Draw()
{}

void Steering::Init(Agent* parent)
{
	if (m_parent != nullptr)
	{
		std::cout << ">> WARNING: Steering already initialized. Call Uninit instead." << std::endl;
		return;
	}
	m_parent = parent;
}

void Steering::Uninit()
{
	Reset();
	m_parent = nullptr;
}

Steering::Steering(std::string name)
	:m_name(name)
{}
Steering::~Steering()
{}

//Steering::Steering(const Steering& other) = delete;
//Steering& Steering::operator=(const Steering& other) = delete;

void Steering::SteerTowards(const sf::Vector2<float>& target, sf::Vector2<float>& result)
{
	sf::Vector2<float> desired = target - m_parent->GetPosition();
	float targetDistance = Vector2LenghtSq(desired);
	if (targetDistance > 0)
	{
		desired = Normailize(desired);
		result.x = desired.x * m_parent->GetVelocity().x;
		result.y = desired.y * m_parent->GetVelocity().y;
	}
	else
	{
		result.x = 0.0f;
		result.y = 0.0f;
	}
}
void Steering::SteerAway(const sf::Vector2<float>& target, sf::Vector2<float>& result)
{
	SteerTowards(-target, result);
}

float Steering::Vector2Lenght(const sf::Vector2<float>& vec)
{
	return std::sqrtf(Vector2LenghtSq(vec));
}
float Steering::Vector2LenghtSq(const sf::Vector2<float>& vec)
{
	return vec.x*vec.x + vec.y*vec.y;
}

sf::Vector2<float> Steering::Normailize(sf::Vector2<float>& vec)
{
	sf::Vector2<float> toRet;
	float lenght = Vector2Lenght(vec);
	if (lenght > 0)
	{
		toRet.x = vec.x / lenght;
		toRet.y = vec.y / lenght;
	}

	return toRet;
}

/*
Checks if the point 1, with a certain tollerance based on velocity, is near the position 2
*/
int Steering::HasReachTarget(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity){
	bool toReturn = ((pos1.x + K_ZERO_TOLLERANCE + abs(velocity.x) * K_10_POTATOES) >= pos2.x) && ((pos1.x - K_ZERO_TOLLERANCE - abs(velocity.x) * K_10_POTATOES) <= pos2.x);
	if (toReturn){
		return ((pos1.y + K_ZERO_TOLLERANCE + abs(velocity.y) * K_10_POTATOES) >= pos2.y) && ((pos1.y - K_ZERO_TOLLERANCE - abs(velocity.y) * K_10_POTATOES) <= pos2.y);
	}
	return false;
}