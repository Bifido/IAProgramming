#pragma once

#include "Steering\Steering.h"

class Seek : public Steering
{
public:
	void Upadate(float dt);
	void Reset();
	//for debug
	void Draw();

	Seek(std::string name, Agent* partent);
};