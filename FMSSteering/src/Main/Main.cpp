//#define Vale
#define Marco
//#define Ricky

#include "SFML\Graphics.hpp"
#include "ViewManager.h"
#include "Constants.h"

#ifndef Ricky
	#ifndef Marco
		#ifdef Vale
			#include "MainVale.cpp"
		#endif
	#else 
		#include "MainMarco.cpp"
	#endif
#else
	#include "MainRicky.cpp"
#endif

using namespace MagicNumber;

void MainLoop();
static void Draw(sf::Sprite sprite);


void DrawTexture(sf::RenderWindow& window){

}

int main(){

	#ifndef Ricky
		#ifndef Marco
			#ifdef Vale
				InitVale();
			#endif
		#else 
			InitMarco();
		#endif
	#else
		InitRicky();
	#endif

	ViewManager& viewMan = ViewManager::GetInstace();

	// create the window
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Son of WhiteSnow");
	// run the program as long as the window is open
	while (window.isOpen()){
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))			{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//TODO updateLogica
		viewMan.Draw(window);
	}

	return 0;
}

void MainLoop(){
	#ifndef Ricky
		#ifndef Marco
			#ifdef Vale
				StartVale();
			#endif
		#else 
			StartMarco();
		#endif
	#else
		StartRicky();
	#endif


	#ifndef Ricky
		#ifndef Marco
			#ifdef Vale
				RunVale();
			#endif
		#else 
			RunMarco();
		#endif
	#else
		RunRicky();
	#endif
}