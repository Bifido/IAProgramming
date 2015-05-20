#include "SFML\Graphics.hpp"

class ViewManager{
	public:
		/* @returns The instance of ViewManager. if is the first time, it create the obj. */
		static ViewManager& GetInstace();
		sf::Sprite& GetSprite();
		//const sf::RenderWindow& GetWindow() const;

	private:
		ViewManager();
		~ViewManager();

		ViewManager(const ViewManager& viewManager) = delete;
		const ViewManager& operator=(const ViewManager& viewManager) = delete;

		sf::Sprite m_Sprite;
		sf::Texture m_Texture;


		sf::Texture	m_Dwarf;
		sf::Texture	m_Grass;

};