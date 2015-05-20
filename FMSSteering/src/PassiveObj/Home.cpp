#include "PassiveObj\Home.h"

Home::Home(unsigned int staminaRecoveredEachFrame)
	:STAMINA_RECOVERED(staminaRecoveredEachFrame){

}

unsigned int Home::GetStaminaRecovered() const{
	return STAMINA_RECOVERED;
}

void Home::SetViewComponent(ViewComponent* newViewComponent){
	viewInfo = newViewComponent;
}

Home::~Home(){ }