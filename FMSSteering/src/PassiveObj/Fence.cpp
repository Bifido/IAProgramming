#include "PassiveObj\Fence.h"
#include "Constants.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
using namespace std;

Fence::Fence(const sf::Vector2<float> newPos,const sf::Vector2<float> fenceSize) :
m_vPosition(newPos),
m_vLowerRightCorner(newPos.x + fenceSize.x, newPos.y + fenceSize.y),
m_vEscapingPoint(newPos.x + fenceSize.x, newPos.y)
{
}

const sf::Vector2<float>& Fence::GetPosition() const{
	return m_vPosition;
}
const sf::Vector2<float>& Fence::GetUpperLeftCornerPos() const{
	return m_vPosition; //yes is the same of the position
}
const sf::Vector2<float>& Fence::GetLowerRightCornerPos() const{
	return m_vLowerRightCorner;	//is position + fenceSize
}

bool Fence::IsPointInside(const sf::Vector2<float>& position) const{
	return	position.x > m_vPosition.x &&
			position.x < m_vLowerRightCorner.x &&
			position.y > m_vPosition.y &&
			position.y < m_vLowerRightCorner.y;
}

const sf::Vector2<float> Fence::GetRandomPointInside() const{
	float x = m_vPosition.x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (m_vLowerRightCorner.x - m_vPosition.x)));
	float y = m_vPosition.y + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (m_vLowerRightCorner.y - m_vPosition.y)));
	return sf::Vector2<float>(x, y);
}
const sf::Vector2<float> Fence::GetRandomPointOutside() const{
	float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float y;
	if (x > m_vEscapingPoint.x){
		y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}
	else{
		y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / m_vEscapingPoint.y));
	}
	return sf::Vector2<float>(x, y);
}
const sf::Vector2<float>& Fence::GetEscapingPoint() const{
	return m_vEscapingPoint;
}

void Fence::SetViewComponent(ViewComponent* viewComponent){
	m_oViewInfo = viewComponent;
}