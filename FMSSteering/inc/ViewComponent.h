#pragma once
#include "SFML\Graphics.hpp"
#include "Vector2.h"

using namespace VectorStruct;
class ViewComponent{
public:
	ViewComponent();
	ViewComponent(const unsigned int spriteIndex,const Vector2& pos, const float degree );
	~ViewComponent();

	void	SetSpriteIndex(const unsigned int spriteIndex);
	int		GetSpriteIndex() const;

private:
	int				spriteIndex;
	Vector2&		pos;
	float			degree;
};