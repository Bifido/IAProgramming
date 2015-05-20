#include "ViewComponent.h"

ViewComponent::ViewComponent(const unsigned int spriteIndex,Vector2& pos, const float degree):
	m_Pos(pos),
	m_SpriteIndex(spriteIndex),
	m_Degree(degree){
}

ViewComponent::~ViewComponent(){}

void		ViewComponent::SetSpriteIndex(const unsigned int spriteIndex){
	m_SpriteIndex = spriteIndex;
}
int			ViewComponent::GetSpriteIndex() const{
	return m_SpriteIndex;
}

void		ViewComponent::SetPos(Vector2& pos){
	m_Pos = pos;
}
Vector2&	ViewComponent::GetPos() const{
	return m_Pos;
}

void		ViewComponent::SetDegree(const float degree){
	m_Degree = degree;
}
float		ViewComponent::GetDegree() const{
	return m_Degree;
}