#pragma once
#include "SFML\System\Vector2.hpp"

// ** Forward dec
class ViewComponent;
class Home;
class Mine;
// ** END

class NanoAgent
{

public:
	const unsigned int MAX_STAMINA;
	const unsigned int MAX_STONE;

	NanoAgent(unsigned int maxStone, unsigned int maxStamina);

	const sf::Vector2<float>& GetPosition() const;
	const sf::Vector2<float>& GetVelocity() const;
	const sf::Vector2<float>& GetTarget() const;
	unsigned int GetStamina() const;
	unsigned int GetCarriedStonesNumber() const;
	ViewComponent* GetViewComponent() const;
	Home* GetHome() const;
	Mine* GetMine() const;

	void SetPosition(const sf::Vector2<float>& newPosition);
	void SetVelocity(const sf::Vector2<float>& newVelocity);
	void SetTarget(const sf::Vector2<float>& newTarget);
	void SetViewComponent(ViewComponent* viewComp);
	void SetHome(Home* nanoHome);
	void SetMine(Mine* nanoMine);

	void SetStamina(unsigned int newStamina);
	unsigned int IncrementStamina(unsigned int staminaToAdd);
	unsigned int DecrementStamina(unsigned int staminaLost);
	
	void SetCarriedStonesNumber(unsigned int newCarriedStonesNumber);
	unsigned int IncrementStoneCarried(unsigned int stoneToAdd);
	unsigned int DecrementStoneCarried(unsigned int stoneToRemove);

	bool HasReachedMaxStone() const;
	bool HasStillStamina() const;
	bool HasEnoughStamina(unsigned int staminaRequired) const;

	~NanoAgent();
private:

	sf::Vector2<float> pos; // each value, go from 0 to 1 (Normalized)
	sf::Vector2<float> velocity;
	sf::Vector2<float> target;

	unsigned int stamina;
	unsigned int numOfCarriedStones;

	ViewComponent* viewInfo;

	Mine* myMine;
	Home* myHome;
};

