#pragma once
#include "SFML\Graphics.hpp"

class ViewComponent{
public:
	ViewComponent();
	~ViewComponent();

	void			SetSprite(const unsigned int spriteIndex);
	sf::Sprite&		GetSprite() const;
	void			SetX(const unsigned int x);
	unsigned int	GetX() const;
	void			SetY(const unsigned int y);
	unsigned int	GetY() const;

private:
	sf::Sprite&		m_Sprite;
	unsigned int	m_X;
	unsigned int	m_Y;
};