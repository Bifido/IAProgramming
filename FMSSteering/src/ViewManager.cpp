#include "Constants.h"
#include "ViewManager.h"
#include <iostream>

using namespace MagicNumber;
using namespace sf;
using namespace std;
/* @returns The instance of ViewManager. if is the first time, it create the obj. */
ViewManager& ViewManager::GetInstace(){
	//Only the first time m_instance is called is created, when the program is closed the dtor is automatically called
	static ViewManager m_instace;
	return m_instace;
}

void ViewManager::AddViewComponent(const ViewComponent& viewComponent){
	m_Agents.push_back(viewComponent);
}

void ViewManager::Draw(RenderWindow& window) {
	// clear the window with black color
	window.clear(sf::Color::Black);

	// draw everything here...
	DrawBackground(window);
	DrawDynamic(window);

	// end the current frame
	window.display();
}


int ViewManager::FromNormalizedToScreenPixelHEIGHT(float pos) const{
	return static_cast<int>(pos * HEIGHT);
}

int ViewManager::FromNormalizedToScreenPixelWIDTH(float pos) const{
	return static_cast<int>(pos * WIDTH);
}

void ViewManager::FromNormalizedToScreenPixel(Vector2<float> pos, int& pixelPosX, int& pixelPosY){
	pixelPosX = FromNormalizedToScreenPixelWIDTH(pos.x);
	pixelPosY = FromNormalizedToScreenPixelHEIGHT(pos.y);
}

void ViewManager::DrawBackground(RenderWindow& window) const{
	window.draw(m_Sprites[BACKGROUND]);
	window.draw(m_Sprites[HUT]);
	window.draw(m_Sprites[MINE]);
	window.draw(m_Sprites[FENCE]);
}

void ViewManager::DrawDynamic(RenderWindow& window){
	//window.draw(m_Sprites[DWARF]);
	//window.draw(m_Sprites[DOG]);
	//window.draw(m_Sprites[SHEEP]);

	Sprite temp;
	for (vector<ViewComponent>::iterator it = m_Agents.begin(); it != m_Agents.end(); ++it){
		//cout << "DRAWING " << it->GetSpriteIndex() << endl;
		temp = m_Sprites[it->GetSpriteIndex()];
		temp.setOrigin(0.5f, 0.5f);
		temp.setPosition(FromNormalizedToScreenPixelWIDTH(it->GetPos().x), FromNormalizedToScreenPixelHEIGHT(it->GetPos().y));
		temp.setRotation(it->GetDegree());
		window.draw(temp);
	}
}

ViewManager::ViewManager(){	
	Sprite temp;

	m_DwarfTexture.loadFromFile("resources/dwarf.png");
	temp.setTexture(m_DwarfTexture);
	temp.setScale(0.5f, 0.5f);
	m_Sprites.push_back(temp);

	m_GrassTexture.loadFromFile("resources/grass.png");
	m_GrassTexture.setRepeated(true);
	temp.setScale(1, 1);
	temp.setTexture(m_GrassTexture);
	temp.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));
	m_Sprites.push_back(temp);

	m_HutTexture.loadFromFile("resources/hut.png");
	temp.setTexture(m_HutTexture);
	temp.setScale(0.5f, 0.5f);
	temp.setTextureRect(IntRect(0, 0, 256, 256));
	temp.setPosition(FromNormalizedToScreenPixelWIDTH(POS_BACKGROUND_HOUSE.x), FromNormalizedToScreenPixelHEIGHT(POS_BACKGROUND_HOUSE.y));
	m_Sprites.push_back(temp);

	m_MineTexture.loadFromFile("resources/mine.png");
	temp.setTexture(m_MineTexture);
	temp.setTextureRect(IntRect(0, 0, 256, 256));
	temp.setPosition(FromNormalizedToScreenPixelWIDTH(POS_BACKGROUND_MINE.x), FromNormalizedToScreenPixelHEIGHT(POS_BACKGROUND_MINE.y));
	m_Sprites.push_back(temp);

	m_FenceTexture.loadFromFile("resources/fence.png");
	temp.setTexture(m_FenceTexture);
	temp.setScale(1, 1);
	temp.setTextureRect(IntRect(0, 0, 256, 256));
	temp.setPosition(FromNormalizedToScreenPixelWIDTH(POS_BACKGROUND_FENCE.x), FromNormalizedToScreenPixelHEIGHT(POS_BACKGROUND_FENCE.y));
	m_Sprites.push_back(temp);

	m_DogTexture.loadFromFile("resources/dog.png");
	temp.setTexture(m_DogTexture);
	temp.setScale(0.5, 0.5);
	temp.setTextureRect(IntRect(0, 0, 64, 64));
	temp.setPosition(0, 0);
	m_Sprites.push_back(temp);

	m_SheepTexture.loadFromFile("resources/sheep.png");
	temp.setTexture(m_SheepTexture);
	//temp.setScale(0.5, 0.5);
	temp.setTextureRect(IntRect(0, 0, 64, 64));
	temp.setPosition(0, 0);
	m_Sprites.push_back(temp);
}
ViewManager::~ViewManager(){
}