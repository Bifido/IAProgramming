//#define Vale
#define Marco
//#define Ricky

#include "SFML\Graphics.hpp"
#include "ViewManager.h"
#include "Constants.h"
#include <Windows.h>

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

float timePreciso();


void DrawTexture(sf::RenderWindow& window){

}

int main(){

	ViewManager& viewMan = ViewManager::GetInstace();

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
	sf::RenderWindow window(sf::VideoMode(MagicNumber::WIDTH, MagicNumber::HEIGHT), "Son of WhiteSnow");

	float previousClock = 0;

	// run the program as long as the window is open
	while (window.isOpen()){
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))			{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				viewMan.ChangeHouseMinePos();*/
		}

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


		viewMan.Draw(window);

		int delta = (timePreciso() - previousClock) * 1000;
		if (delta < MagicNumber::deltaTimeMill)
			Sleep(MagicNumber::deltaTimeMill - delta);
		previousClock = timePreciso();
	}

	return 0;
}

float timePreciso()
{
	static __int64 start = 0;
	static __int64 frequency = 0;

	if (start == 0)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&start);
		QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
		return 0.0f;
	}

	__int64 counter = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&counter);
	return (float)((counter - start) / double(frequency));
}