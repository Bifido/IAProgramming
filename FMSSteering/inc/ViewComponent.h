#pragma once
#include "SFML\Graphics.hpp"
#include "Vector2.h"

using namespace VectorStruct;
class ViewComponent{
public:
	ViewComponent(const unsigned int spriteIndex, const Vector2& pos, const float degree );
	~ViewComponent();

	void				SetSpriteIndex(const unsigned int spriteIndex);
	int					GetSpriteIndex() const;

	//void				SetPos(const Vector2& pos);
	const Vector2&		GetPos() const;

	void				SetDegree(const float degree);
	float				GetDegree() const;

private:
	int					m_SpriteIndex;
	const Vector2&		m_Pos;
	float				m_Degree;
};