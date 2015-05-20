#pragma once
#include "SFML\Graphics.hpp"
#include "Vector2.h"

using namespace VectorStruct;
class ViewComponent{
public:
	ViewComponent(const unsigned int spriteIndex, Vector2& pos, const float degree );
	~ViewComponent();

	void		SetSpriteIndex(const unsigned int spriteIndex);
	int			GetSpriteIndex() const;

	void		SetPos(Vector2& pos);
	Vector2&	GetPos() const;

	void		SetDegree(const float degree);
	float		GetDegree() const;

private:
	int				m_SpriteIndex;
	Vector2&		m_Pos;
	float			m_Degree;
};