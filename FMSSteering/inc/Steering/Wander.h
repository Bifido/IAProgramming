#pragma once

#include "Steering\Steering.h"

class Wander : public Steering
{
	const float K_CIRCLE_DISTANCE = 0.03f;
	const float K_CIRCLE_RADIUS = 0.1f;
	const float K_MAX_ANGLE = 0.1f;
public:
	void Update(float dt);
	void Reset();
	//for debug
	void Draw();

	Wander(std::string name);
private:
	float m_fWanderAngle;
	sf::Vector2<float> CalculateWander();
};