#include "ViewComponent.h"
#include "ViewManager.h"
#include "SFML\System\Vector2.hpp"

using namespace sf;
ViewComponent::ViewComponent(const unsigned int spriteIndex, const Vector2<float>& pos, const float degree) :
	m_Pos(pos),
	m_SpriteIndex(spriteIndex),
	m_Degree(degree){

	ViewManager::GetInstace().AddViewComponent(*this);
}

ViewComponent::~ViewComponent(){}

void		ViewComponent::SetSpriteIndex(const unsigned int spriteIndex){
	m_SpriteIndex = spriteIndex;
}
int			ViewComponent::GetSpriteIndex() const{
	return m_SpriteIndex;
}

const Vector2<float>&	ViewComponent::GetPos() const{
	return m_Pos;
}

void		ViewComponent::SetDegree(const float degree){
	m_Degree = degree;
}
float		ViewComponent::GetDegree() const{
	return m_Degree;
}