#pragma once

#include "Steering\Steering.h"

class Evade : public Steering
{
public:
	void Update(float dt);
	void Reset();
	//for debug
	void Draw();

	Evade(std::string name);
};