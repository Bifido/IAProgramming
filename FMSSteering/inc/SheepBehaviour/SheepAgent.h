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
	SheepAgent(bool inInFence = true, bool isEscaping = false);

	void SetFence(const Fence& sheepFence);
	Fence* GetFence() const;

	const bool IsInFence() const;
	const bool IsEscaping() const;

	void SetInFence(const bool inFence);
	void SetEscaping(const bool escaping);

	~SheepAgent(){};

	void FSMAdd(FSMCore<SheepAgent>* sharedStates);
	void FSMRemove();
	void FSMRun();

private:
	bool m_bIsInFence;
	bool m_bIsEscaping;

	Fence* m_oFence;
	FiniteStateMachine<SheepAgent> m_oFsm;
};

