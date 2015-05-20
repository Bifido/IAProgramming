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

unsigned int Mine::DecrementStonesNumber(unsigned int stoneToRemove){
	numberOfStoneAvailable -= stoneToRemove;
	numberOfStoneAvailable > 0 ? numberOfStoneAvailable : 0;
	
	return numberOfStoneAvailable;
}

void Mine::SetViewComponent(ViewComponent* newViewComponent){
	viewInfo = newViewComponent;
}

Mine::~Mine(){ }