#pragma once
#include "SFML\System\Vector2.hpp"

namespace MagicNumber{
	//FRAME RATE
	const float deltaTime = 0.016f;

	//SCREEN RESOLUTION
	const int HEIGHT = 600;
	const int WIDTH = 800;

	//USE THIS AS TARGET FOR DWARFS
	static sf::Vector2<float> POS_NANO_HOUSE(0.21f, 0.28f);
	static sf::Vector2<float> POS_NANO_MINE(0.81f, 0.58f);

	//USED ONLY TO DRAW BACKGROUND
	static sf::Vector2<float> POS_BACKGROUND_HOUSE(0.16f, 0.10f);
	static sf::Vector2<float> POS_BACKGROUND_MINE(0.77f, 0.41f);

	static float GENERATION_HOUSE_LO(0.1f);
	static float GENERATION_HOUSE_HI(0.6f);

	static float GENERATION_MINE_LO(0.3f);
	static float GENERATION_MINE_HI(0.8f);

	//fence never changes
	static const sf::Vector2<float> POS_BACKGROUND_FENCE(0.05f, 0.53f);		//this is the left upper corner
	static const sf::Vector2<float> FENCE_SIZE(0.3f, 0.35f);
	
	//TODO probably deletable
	static const sf::Vector2<float> FENCE_LOWER_RIGHT(POS_BACKGROUND_FENCE.x + FENCE_SIZE.x, POS_BACKGROUND_FENCE.y + FENCE_SIZE.y);		//this is the left upper corner
}