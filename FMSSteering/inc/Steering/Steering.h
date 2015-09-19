#pragma once
#include <string>
#include "SFML\System\Vector2.hpp"

// ** Forward dec
class Agent;
// ** END

class Steering
{
public:
	virtual void Upadate(float dt);
	virtual void Reset();
	//for debug
	virtual void Draw();

	int HasReachTarget(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2, const sf::Vector2<float>& velocity);
protected:
	Steering(std::string name, Agent* partent);
	virtual ~Steering();
	Steering(const Steering& other) = delete;
	Steering& operator=(const Steering& other) = delete;

	//Support functions
	void SteerTowards(const sf::Vector2<float>& target, sf::Vector2<float>& result);
	void SteerAway(const sf::Vector2<float>& target, sf::Vector2<float>& result);

	float Vector2Lenght(const sf::Vector2<float>& vec);
	float Vector2LenghtSq(const sf::Vector2<float>& vec);
	sf::Vector2<float> Normailize(sf::Vector2<float>& vec);

	//Agent because it use only function of parent Agent that are not virtual
	Agent* m_parent;

private:
	//for debug
	std::string m_name;
};