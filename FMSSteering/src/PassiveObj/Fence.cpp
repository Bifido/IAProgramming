#include "PassiveObj\Fence.h"
#include "Constants.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
using namespace std;

Fence::Fence(const sf::Vector2<float> newPos,const sf::Vector2<float> fenceSize) :
m_vPosition(newPos),
m_vLowerLeftCorner(newPos.x,newPos.y - fenceSize.y),
m_vUpperRightCorner(newPos.x + fenceSize.x, newPos.y)
{
	/*cout << "fence2 Costructor" << endl;
	printf("%f ", GetPosition().x);
	printf("%f ", GetPosition().y);
	cout << endl;
	printf("%f ", GetLowerLeftCornerPos().x);
	printf("%f ", GetLowerLeftCornerPos().y);
	cout << endl;
	printf("%f ", GetUpperRightCornerPos().x);
	printf("%f ", GetUpperRightCornerPos().y);
	cout << "fence2 Costructor end" << endl;*/
}

const sf::Vector2<float>& Fence::GetPosition() const{
	return m_vPosition;
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