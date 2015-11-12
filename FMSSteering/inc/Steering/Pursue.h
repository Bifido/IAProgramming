#pragma once

#include "Steering\Steering.h"

class Pursue : public Steering
{
	const float K_NUMBER_OF_PREDICTION_FRAME = 4.0f;
public:
	void Update(float dt);
	void Reset();
	//for debug
	void Draw();

	Pursue(std::string name);
};