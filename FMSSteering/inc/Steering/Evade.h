#pragma once

#include "Steering\Steering.h"

class Evade : public Steering
{
public:
	void Upadate(float dt);
	void Reset();
	//for debug
	void Draw();

	Evade(std::string name, Agent* partent);
};