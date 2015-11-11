#pragma once

#include "Steering\Steering.h"

class Arrive : public Steering
{
public:
	void Init(Agent* parent, float arriveDistance, float minSpeed);
	void Update(float dt);
	void Reset();
	//for debug
	void Draw();

	Arrive(std::string name);
private:
	void Init(Agent* parent); // <-- Hidden. The arrive can be initialized only with also and arriveDistance and minSpeed

	void SteerArrive(const sf::Vector2<float>& target, sf::Vector2<float>& result);

	float m_arriveDistance;
	float m_minSpeed;
};