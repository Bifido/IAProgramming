#pragma once
#include "SFML\System\Vector2.hpp"
#include "Agent.h"
#include "DogBehaviour\DogAgent.h"
#include "FiniteStateMachine.h"
#include <string>

// ** Forward dec
class ViewComponent;
class Fence;
// ** END

class SheepAgent : public Agent
{

public:
	//Creates Sheep already in fence
	SheepAgent(std::string name, bool inInFence = true, bool isEscaping = false, bool isCatched = false);

	void SetFence(Fence* sheepFence);
	const Fence* GetFence() const;

	const bool IsInFence() const;
	const bool IsEscaping() const;
	const bool IsCatched() const;

	void SetInFence(const bool inFence);
	void SetEscaping(const bool escaping);
	
	void SetCatched(const bool i_bCatched);
	void SetDog(DogAgent* i_pDog);
	DogAgent* GetDog() const;

	~SheepAgent(){};

	void FSMAdd(FSMCore<SheepAgent>* sharedStates);
	void FSMRemove();
	void FSMRun(float dt);

private:
	const sf::Vector2<float> SHEEP_SPEED = sf::Vector2<float>(0.0005f, 0.0005f);

	bool m_bIsInFence;
	bool m_bIsEscaping;
	bool m_bIsCatched;

	Fence* m_oFence;
	FiniteStateMachine<SheepAgent> m_oFsm;
	DogAgent* m_pDogAgent;
};

