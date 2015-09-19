#pragma once
#include "SFML\System\Vector2.hpp"
#include "Agent.h"
#include "FiniteStateMachine.h"
#include <string>

// ** Forward dec
class ViewComponent;
class Home;
class Mine;
class Steering;
// ** END

class NanoAgent : public Agent
{

public:
	const unsigned int MAX_STAMINA;
	const unsigned int MAX_STONE;
	const unsigned int STONES_RATIO;
	const unsigned int STAMINA_USAGE;
	const unsigned int STAMINA_RECOVER;

	NanoAgent(std::string name, int maxStone, unsigned int maxStamina, unsigned int stonesRatio = 1,
		unsigned int staminaUsage = 1, unsigned int staminaRecover = 1);

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

	void SetStaminaRecovering(bool staminaRecovering);
	bool IsInStaminaRecovering() const;

	~NanoAgent();

	void FSMAdd(FSMCore<NanoAgent>* sharedStates);
	void FSMRemove();
	void FSMRun(float dt);

private:

	unsigned int m_stamina;
	unsigned int m_numOfCarriedStones;
	bool m_staminaRecovering;

	Mine* myMine;
	Home* myHome;
	FiniteStateMachine<NanoAgent> fsm;
};

