#include <iostream>
#include <stdlib.h>
#include "SDL/include/SDL.h"


#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")


int main(int argc, char* argv[]) {

	bool stoprect1 = false; 
	bool loading_screen = true;


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

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//create a smolll rectangle
			
			SDL_Rect  rect1 = { 0, 0, 69, 420 };
			SDL_Rect  rect2 = { 200, 200, 420, 69 };

			SDL_Rect PedroRect = { 0, 0 , 300, 300 };


			while (!quit) {

				//Fill the surface with a color
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x60, 0x16, 0xfa));

				if (loading_screen) {
					

					//fill the smoll rectangle
					SDL_FillRect(screenSurface, &rect1, SDL_MapRGB(screenSurface->format, 0xfc, 0x17, 0x08));

					//fill the smoll rectangle 2 
					SDL_FillRect(screenSurface, &rect2, SDL_MapRGB(screenSurface->format, 0xff, 0xaa, 0xaa));



					//move the smoll rectangle
					if (!stoprect1) {
						rect1.x++;
						rect1.y++;
						if (rect1.x > screenSurface->w) rect1.x = 0;
						if (rect1.y > screenSurface->h) rect1.y = 0;
					}

					//fill the smoll rectangle 2 
					SDL_FillRect(screenSurface, &rect2, SDL_MapRGB(screenSurface->format, 0xff, 0xaa, 0x


					//move the smoll rectangle
					rect2.x++;
					rect2.y++;
					if (rect2.x > screenSurface->w) rect2.x = 0;
					if (rect2.y > screenSurface->h) rect2.y = 0;
				}
				else {
					delete(&rect1);
					delete(&rect2);
				}

				//Update the surface
				SDL_UpdateWindowSurface(window);

				while (SDL_PollEvent(&e) != 0){
						//User requests quit

						if (e.type == SDL_QUIT)
						{
							quit = true;
						}
						//User presses a key
						else if (e.type == SDL_KEYDOWN)
						{
							switch (e.key.keysym.sym)
							{
							case SDLK_SPACE:
								rect1.x = 0;
								rect1.y = 0;
								rect1.w = screenSurface->w;
								rect1.h = screenSurface->h;
								stoprect1 = true;
								break;

							case SDLK_ESCAPE:
								quit = true;
								break;

							case SDLK_g: 
								loading_screen = false;
								break;


							case SDLK_w: 
								PedroRect.y -= 20;
							case SDLK_a:
								PedroRect.x -= 20;
								break;
							default:
								break;

							}


						}



				}

					
				

			}


		}
	}

	return 0;

}