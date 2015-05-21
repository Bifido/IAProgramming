#pragma once
#include "SFML\System\Vector2.hpp"

class ViewComponent{
public:
	ViewComponent(const unsigned int spriteIndex, const sf::Vector2<float>& pos, const float degree );
	~ViewComponent();

	void							SetSpriteIndex(const unsigned int spriteIndex);
	int								GetSpriteIndex() const;

	const sf::Vector2<float>&	GetPos() const;

	void							SetDegree(const float degree);
	float							GetDegree() const;

	bool IsDrawable();
	void SetDrawable(bool drawable);

private:
	int								m_SpriteIndex;
	const sf::Vector2<float>&	m_Pos;
	float							m_Degree;
	bool							m_Drawable;
};