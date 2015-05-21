#pragma once
#include "SFML\System\Vector2.hpp"
#include "Agent.h"

// ** Forward dec
class ViewComponent;
class Home;
class Mine;
// ** END

class NanoAgent : public Agent
{

public:
	const unsigned int MAX_STAMINA;
	const unsigned int MAX_STONE;

	NanoAgent(unsigned int maxStone, unsigned int maxStamina);

	unsigned int GetStamina() const;
	unsigned int GetCarriedStonesNumber() const;
	Home* GetHome() const;
	Mine* GetMine() const;

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

	unsigned int stamina;
	unsigned int numOfCarriedStones;

	Mine* myMine;
	Home* myHome;
};

