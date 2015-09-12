#pragma once
#include "SFML\System\Vector2.hpp"
#include "Agent.h"
#include "FiniteStateMachine.h"

// ** Forward dec
class ViewComponent;
class Fence;
// ** END

class SheepAgent : public Agent
{

public:
	//Creates Sheep already in fence
	SheepAgent(bool inInFence = true, bool isEscaping = false, bool isCatched = false);

	void SetFence(Fence* sheepFence);
	const Fence* GetFence() const;

	const bool IsInFence() const;
	const bool IsEscaping() const;
	const bool IsCatched() const;

	void SetInFence(const bool inFence);
	//TODO VALE: can become true if dog_is_near_X false otherwise if i have dog position
	void SetEscaping(const bool escaping);
	
	//TODO RICKY DOG should use only this, If it's already in fence can't be catched otherwise yes
	void SetCatched();

	~SheepAgent(){};

	void FSMAdd(FSMCore<SheepAgent>* sharedStates);
	void FSMRemove();
	void FSMRun();

private:
	const sf::Vector2<float> SHEEP_SPEED = sf::Vector2<float>(0.0005f, 0.0005f);

	bool m_bIsInFence;
	bool m_bIsEscaping;
	bool m_bIsCatched;

	Fence* m_oFence;
	FiniteStateMachine<SheepAgent> m_oFsm;
};

