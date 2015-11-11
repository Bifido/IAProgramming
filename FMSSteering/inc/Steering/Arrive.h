#pragma once

#include "Steering\Steering.h"

class Arrive : public Steering
{
public:
	void Upadate(float dt);
	void Reset();
	//for debug
	void Draw();

	Arrive(std::string name, Agent* partent, float arriveDistance, float minSpeed);
private:
	void SteerArrive(const sf::Vector2<float>& target, sf::Vector2<float>& result);

	float m_arriveDistance;
	float m_minSpeed;
};