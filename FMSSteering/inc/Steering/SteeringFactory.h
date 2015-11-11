#pragma once
//** Forward dec
class Steering;
class Agent;
//** End

class SteeringFactory
{

public:
	enum SteeringType
	{
		Seek,
		Evade,
		Arrive
	};

	static Steering* BuildSteering(SteeringType);
	static void	ReleaseSteering(Steering*&);
};