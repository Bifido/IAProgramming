#pragma once
#include "State.h"
#include "SFML\System\Vector2.hpp"

class DogAgent;

class StateCatchingSheep : public State<DogAgent>
{
public:
	StateCatchingSheep();
	~StateCatchingSheep();

	void OnEnter(DogAgent& agent) const;
	void OnExit(DogAgent& agent) const;
	void Update(DogAgent& agent) const;
	FSMStates CheckTransition(DogAgent& agent) const;
};