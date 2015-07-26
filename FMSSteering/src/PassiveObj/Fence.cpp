#include "PassiveObj\Fence.h"
#include "Constants.h"

const sf::Vector2<float>& Fence::GetPosition() const{
	return MagicNumber::POS_BACKGROUND_FENCE;
}
const sf::Vector2<float>& Fence::GetLowerLeftCornerPos() const{
	return m_vLowerLeftCorner;
}
const sf::Vector2<float>& Fence::GetUpperRightCornerPos() const{
	return m_vUpperRightCorner;
}

void Fence::SetViewComponent(ViewComponent* viewComponent){
	m_oViewInfo = viewComponent;
}