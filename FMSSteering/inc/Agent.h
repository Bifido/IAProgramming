#pragma once
#include "SFML\System\Vector2.hpp"
#include "Steering\SteeringFactory.h"
#include <string>

// ** Forward dec
class ViewComponent;
class Steering;
//template <typename Agent>
//class FiniteStateMachine;
// ** END

class Agent
{

public:
	const sf::Vector2<float>& GetPosition() const;
	const sf::Vector2<float>& GetVelocity() const;
	const sf::Vector2<float>& GetTarget() const;
	float GetMaxSpeed() const;
	Steering* GetCurrentSteering() const;
	ViewComponent* GetViewComponent() const;

	void SetPosition(const sf::Vector2<float>& newPosition);
	void SetVelocity(const sf::Vector2<float>& newVelocity);
	void SetTarget(const sf::Vector2<float>& newTarget);
	void SetMaxSpeed(float maxSpeed);
	Steering* SetCurrentSteering(SteeringFactory::SteeringType);
	void SetViewComponent(ViewComponent* viewComp);

	Steering* RemoveCurrentSteering();

	std::string GetName();

protected:
	Agent(std::string name);
	~Agent();

private:

	sf::Vector2<float> m_pos; // each value, go from 0 to 1 (Normalized)
	sf::Vector2<float> m_velocity;
	sf::Vector2<float> m_target;
	Steering* m_currentSteering;

	std::string m_name;

	float m_maxSpeed;

	//FiniteStateMachine<Agent>* fsm;

	ViewComponent* m_viewInfo;
};