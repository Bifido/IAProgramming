#include "SFML\Graphics.hpp"

class ViewManager{
	public:
		enum SPRITES{DWARF = 0,BACKGROUND = 1, HUT = 2, MINE = 3, FENCE = 4, COUNT};

		/* @returns The instance of ViewManager. if is the first time, it create the obj. */
		static ViewManager& GetInstace();
		sf::Sprite& GetSprite();
		void Draw(sf::RenderWindow& window) const;

	private:
		ViewManager();
		~ViewManager();

		void DrawBackground(sf::RenderWindow& window) const;

		ViewManager(const ViewManager& viewManager) = delete;
		const ViewManager& operator=(const ViewManager& viewManager) = delete;

		sf::Sprite m_Background;
		sf::Sprite m_Hut;
		sf::Sprite m_Mine;

		sf::Texture	m_DwarfTexture;
		sf::Texture	m_GrassTexture;
		sf::Texture m_HutTexture;
		sf::Texture m_MineTexture;
		sf::Texture m_FenceTexture;

		std::vector<sf::Sprite> m_Sprites;
};