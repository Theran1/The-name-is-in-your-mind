#include <iostream>
#include <stdlib.h>
#include "SDL/include/SDL.h"


#pragma comment(lib, "SDL/x86/SDL2.lib")
#pragma comment(lib, "SDL/x86/SDL2main.lib")


int main(int argc, char* argv[]) {


	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize Weboooon! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Mah 1st Windo M8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created Webooon! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x60, 0x66, 0xf0));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	

		while (1) {




		}





		return 0;
	}
}