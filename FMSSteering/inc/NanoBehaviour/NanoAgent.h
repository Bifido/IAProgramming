#pragma once
#include "Vector2.h"

// ** Forward dec
class ViewComponent;
// ** END

class NanoAgent
{

public:
	const unsigned int MAX_STAMINA;
	const unsigned int MAX_STONE;

	NanoAgent(unsigned int maxStone, unsigned int maxStamina);

	const VectorStruct::Vector2& GetPosition() const;
	const VectorStruct::Vector2& GetVelocity() const;
	unsigned int GetStamina() const;
	unsigned int GetCarriedStonesNumber() const;
	ViewComponent* GetViewComponent() const;

	void SetPosition(const VectorStruct::Vector2& newPosition);
	void SetVelocity(const VectorStruct::Vector2& newVelocity);
	void SetViewComponent(ViewComponent* viewComp);
	
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

	VectorStruct::Vector2 pos; // each value, go from 0 to 1 (Normalized)
	VectorStruct::Vector2 velocity;

	unsigned int stamina;
	unsigned int numOfCarriedStones;

	ViewComponent* viewInfo;
};

