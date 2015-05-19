#define Vale
//#define Marco
//#define Ricky

#include "SFML\Graphics.hpp"

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
void MainLoop();


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

	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Son of WhiteSnow");
	// run the program as long as the window is open
	while (window.isOpen())		{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))			{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
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