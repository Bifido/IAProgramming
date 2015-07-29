#include "PassiveObj\Fence.h"
#include "Constants.h"
#include <cstdlib>
#include <ctime>


Fence::Fence() : 
m_vLowerLeftCorner(MagicNumber::POS_BACKGROUND_FENCE.x, MagicNumber::POS_BACKGROUND_FENCE.y - MagicNumber::FENCE_SIZE.y),
m_vUpperRightCorner(MagicNumber::POS_BACKGROUND_FENCE.x + MagicNumber::FENCE_SIZE.x, MagicNumber::POS_BACKGROUND_FENCE.y)
{
}


const sf::Vector2<float>& Fence::GetPosition() const{
	return MagicNumber::POS_BACKGROUND_FENCE;
}
const sf::Vector2<float>& Fence::GetLowerLeftCornerPos() const{
	return m_vLowerLeftCorner;
}
const sf::Vector2<float>& Fence::GetUpperRightCornerPos() const{
	return m_vUpperRightCorner;
}

bool Fence::IsPointInside(const sf::Vector2<float>& position) const{
	return	position.x > m_vLowerLeftCorner.x &&
			position.x < m_vUpperRightCorner.x &&
			position.y > m_vLowerLeftCorner.y &&
			position.y < m_vUpperRightCorner.y;
}

const sf::Vector2<float>& Fence::GetRandomPointInside() const{
	float x = m_vLowerLeftCorner.x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (m_vUpperRightCorner.x - m_vLowerLeftCorner.x)));
	float y = m_vLowerLeftCorner.y + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (m_vUpperRightCorner.y - m_vLowerLeftCorner.y)));
	return sf::Vector2<float>(x, y);
}
const sf::Vector2<float>& Fence::GetRandomPointOutside() const{
	float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float y;
	if (x > m_vUpperRightCorner.x){
		y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}
	else{
		y = m_vUpperRightCorner.y + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0f - m_vUpperRightCorner.y)));
	}
	return sf::Vector2<float>(x, y);
}

void Fence::SetViewComponent(ViewComponent* viewComponent){
	m_oViewInfo = viewComponent;
}