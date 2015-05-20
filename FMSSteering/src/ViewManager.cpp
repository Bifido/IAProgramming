#include "ViewManager.h"
#include <iostream>
using namespace sf;
using namespace std;
/* @returns The instance of ViewManager. if is the first time, it create the obj. */
ViewManager& ViewManager::GetInstace(){
	//Only the first time m_instance is called is created, when the program is closed the dtor is automatically called
	static ViewManager m_instace;
	return m_instace;
}

Sprite& ViewManager::GetSprite(){
	return m_Sprite;
}

ViewManager::ViewManager(){
	m_Texture.create(64, 64);
	
	
	m_Dwarf.loadFromFile("resources/dwarf.png");
	m_Grass.loadFromFile("resources/grass.png");
	m_Grass.setRepeated(true);
	
	m_Sprite.setTexture(m_Grass);
	m_Sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
	/*m_Texture.update(m_Dwarf);
	m_Sprite.setTexture(m_Texture);*/
}

ViewManager::~ViewManager(){
}