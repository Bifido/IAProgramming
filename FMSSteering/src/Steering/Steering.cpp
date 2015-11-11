#include "Steering\Steering.h"
#include "Agent.h"

void Steering::Upadate(float dt)
{}
void Steering::Reset()
{}
void Steering::Draw()
{}

Steering::Steering(std::string name, Agent* partent)
	:m_name(name), m_parent(partent)
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
		desired = Normailize(desired) * m_parent->GetMaxSpeed();
		result = desired - m_parent->GetVelocity();
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
	bool toReturn = ((pos1.x + 0.01f + abs(velocity.x) * 10) >= pos2.x) && ((pos1.x - 0.01f - abs(velocity.x) * 10) <= pos2.x);
	if (toReturn){
		return ((pos1.y + 0.01f + abs(velocity.y) * 10) >= pos2.y) && ((pos1.y - 0.01f - abs(velocity.y) * 10) <= pos2.y);
	}
	return false;
}