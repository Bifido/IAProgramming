#include "SFML\Graphics.hpp"
#include "ViewComponent.h"

class ViewManager{
	public:
		enum SPRITES{DWARF = 0,BACKGROUND = 1, HUT = 2, MINE = 3, FENCE = 4, DOG=5 ,SHEEP=6, COUNT};

		/* @returns The instance of ViewManager. if is the first time, it create the obj. */
		static ViewManager& GetInstace();

		void AddViewComponent(const ViewComponent& viewComponent);
		
		/**
		* Draw the sprites
		*/
		void Draw(sf::RenderWindow& window);

		/**
		* Transform the pos normalized between 0 to 1 in an integer between 0 to screenSize HEIGHT
		* @NOTE
		* if the transformation is not precise, the value is trunc into the nearest small integer
		*/
		int FromNormalizedToScreenPixelHEIGHT(float pos) const;

		/**
		* Transform the pos normalized between 0 to 1 in an integer between 0 to screenSize WIDTH
		* @NOTE
		* if the transformation is not precise, the value is trunc into the nearest small integer
		*/
		int FromNormalizedToScreenPixelWIDTH(float pos) const;

		/**
		* Transform the pos normalized between 0 to 1 in an integer between 0 to screenSize
		* @NOTE
		* if the transformation is not precise, the value is trunc into the nearest small integer
		* @Param
		* pixelPosX = output variable
		* pixelPosY = output variable
		*/
		void FromNormalizedToScreenPixel(sf::Vector2<float> pos, int& pixelPosX, int& pixelPosY);

	private:
		ViewManager();
		~ViewManager();

		void DrawBackground(sf::RenderWindow& window) const;
		void DrawDynamic(sf::RenderWindow& window);

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
		sf::Texture m_DogTexture;
		sf::Texture m_SheepTexture;

		std::vector<sf::Sprite>			m_Sprites;
		std::vector<ViewComponent>		m_Agents;
};