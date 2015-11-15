#include "PassiveObj\Mine.h"

Mine::Mine(unsigned int maxStoneNumber):
	MAX_STONES_NUMBER(maxStoneNumber),
	numberOfStoneAvailable(maxStoneNumber),
	viewInfo(nullptr){

}

unsigned int Mine::GetActualStonesNumber() const{
	return numberOfStoneAvailable;
}

ViewComponent* Mine::GetViewComponent() const{
	return viewInfo;
}

const sf::Vector2<float>& Mine::GetPosition() const{
	return pos;
}

unsigned int Mine::DecrementStonesNumber(unsigned int stoneToRemove){
	if (numberOfStoneAvailable > stoneToRemove)
		numberOfStoneAvailable -= stoneToRemove;
	else
		numberOfStoneAvailable = 0;
	
	return numberOfStoneAvailable;
}

void Mine::SetViewComponent(ViewComponent* newViewComponent){
	viewInfo = newViewComponent;
}

void Mine::SetPosition(const sf::Vector2<float>& newPos){
	pos = newPos;
}

Mine::~Mine(){ }