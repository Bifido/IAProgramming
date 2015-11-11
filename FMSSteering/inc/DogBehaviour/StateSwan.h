#pragma once
#include "State.h"
#include "SFML\System\Vector2.hpp"

class DogAgent;

class StateSwan : public State<DogAgent>
{
public:
	StateSwan();
	~StateSwan();

	void OnEnter(DogAgent& agent) const;
	void OnExit(DogAgent& agent) const;
	void Update(DogAgent& agent, float) const;
	FSMStates CheckTransition(DogAgent& agent) const;
	std::string GetStateName() const;
};