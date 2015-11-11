#pragma once
#include "SFML\System\Vector2.hpp"
#include "Agent.h"
#include "FiniteStateMachine.h"

// ** Forward dec
class ViewComponent;
class SheepAgent;
class Fence;
// ** END

class DogAgent : public Agent
{

public:
	DogAgent(bool i_bIsCatching = false, bool i_bHasCatched = false);
	~DogAgent(){};

	void SetFence(Fence* i_pSheepFence);
	const Fence* GetFence() const;

	void SetSheep(SheepAgent* i_pSheep);
	SheepAgent* GetSheep() const;

	const bool CanStartCatching();
	const bool IsCatching() const;
	void SetCatching(const bool i_bIsCatching);
	
	const bool CanCatch();
	const bool HasCatch() const;
	void SetCatched(const bool i_bHaveCatched);

	void FSMAdd(FSMCore<DogAgent>* i_pSharedStates);
	void FSMRemove();
	void FSMRun();

private:
	const sf::Vector2<float> DOG_SPEED = sf::Vector2<float>(0.0006f, 0.0006f);
	const float SHEEP_CATCHED_DISTANCE = 0.05f;
	const float SHEEP_CATCHING_DISTANCE = 0.18f;

	bool m_bIsCatching;
	bool m_bHasCatched;

	Fence* m_pFence;
	FiniteStateMachine<DogAgent> m_oFsm;
	SheepAgent* m_pSheepAgent;
};

