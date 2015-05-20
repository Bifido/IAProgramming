#include "PassiveObj\Home.h"

Home::Home(unsigned int staminaRecoveredEachFrame)
	:STAMINA_RECOVERED(staminaRecoveredEachFrame){

}

unsigned int Home::GetStaminaRecovered() const{
	return STAMINA_RECOVERED;
}

const sf::Vector2<float>& Home::GetPosition() const{
	return pos;
}

void Home::SetViewComponent(ViewComponent* newViewComponent){
	viewInfo = newViewComponent;
}

void Home::SetPosition(const sf::Vector2<float>& newPos){
	pos = newPos;
}

Home::~Home(){ }