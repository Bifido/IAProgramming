#pragma once

#include "Steering\Steering.h"

class Seek : public Steering
{
public:
	void Update(float dt);
	void Reset();
	//for debug
	void Draw();

	Seek(std::string name);
};