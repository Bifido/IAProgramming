#pragma once
#include "SFML\System\Vector2.hpp"

// ** Forward dec
class ViewComponent;
// ** END

class Agent
{

public:

	Agent();

	const sf::Vector2<float>& GetPosition() const;
	const sf::Vector2<float>& GetVelocity() const;
	const sf::Vector2<float>& GetTarget() const;
	ViewComponent* GetViewComponent() const;

	void SetPosition(const sf::Vector2<float>& newPosition);
	void SetVelocity(const sf::Vector2<float>& newVelocity);
	void SetTarget(const sf::Vector2<float>& newTarget);
	void SetViewComponent(ViewComponent* viewComp);

	~Agent();
private:

	sf::Vector2<float> pos; // each value, go from 0 to 1 (Normalized)
	sf::Vector2<float> velocity;
	sf::Vector2<float> target;

	ViewComponent* viewInfo;
};