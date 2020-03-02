#include <iostream>
#include <stdlib.h>
#include "SDL/include/SDL.h"
#include "SDL2_image/include/SDL_image.h"


#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL2_image/lib_x86/SDL2_image.lib")


int main(int argc, char* argv[]) {

	
	//stop loading
	bool loading_screen = true;


	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//to create and render
	SDL_Surface* Background = NULL;
	SDL_Surface* Bullet = NULL;
	SDL_Surface* Ship = NULL;

	SDL_Rect shipRect = { 69, 420, 200, 200 };
	SDL_Rect BulletRect = { shipRect.x + shipRect.w, shipRect.y + (shipRect.h / 2), 50, 25 };

	//the creator of everything
	SDL_Renderer* renderer = NULL;



	//Initialize SDL
	if ( (SDL_Init(SDL_INIT_VIDEO)< 0))
	{
		printf("SDL could not initialize Weboooon! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Mah 1st Windo M8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 720, SDL_WINDOW_SHOWN);

		/*SDL_Surface* surfa = IMG_Load();*/


		if (window == NULL)
		{
			printf("Window could not be created Webooon! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{

			//Main loop flag
			bool quit = false;


			//other bools
			bool rect1_move = true;
			bool shoot = false;

			//Event handler
			SDL_Event e;

			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Create the images, make sure they work etc, with teh renderer
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);  //the window is where to render, the -1: Unkown
			if (renderer == NULL) {
				std::cout << " Renderer could not be created, you fool" << std::endl;
				std::cout << "SDL_error" <<SDL_GetError() << std::endl;

			}
			else {
				int flags = IMG_INIT_JPG | IMG_INIT_PNG;
				if (IMG_Init(flags) & flags != flags) {
					std::cout << " IMG could not be created, you fool" << std::endl;
					std::cout << "SDL_error" << IMG_GetError() << std::endl;
				}
				else {
					


					Bullet = IMG_Load("Bullet.jpg");
					if (!Bullet) {
						std::cout << "IMG_Load: " << IMG_GetError() << std::endl;
					}

					Background = IMG_Load("Background.jpg");
					if (!Background) {
						std::cout << "IMG_Load: " << IMG_GetError() << std::endl;
					}

					Ship = IMG_Load("Ship.png");
					if (!Ship) {
						std::cout << "IMG_Load: " << IMG_GetError() << std::endl;
					}
				}


			}

			//Create the textures
			SDL_Texture* shipTexture = SDL_CreateTextureFromSurface(renderer, Ship);
			SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, Background);
			SDL_Texture* bulletTexture = SDL_CreateTextureFromSurface(renderer, Bullet);
			


		


			//create a smolll rectangle

			SDL_Rect  rect1 = { 0, 0, 690, 420 };
			SDL_Rect  rect2 = { 100, 250, 420, 69 };

	/*		SDL_Rect PedroRect = { 300, 300 , 300, 300 };*/


			while (!quit) {                            //MAin Loop


				

				if (loading_screen) { //loading screen
					//Fill the surface with a color
					SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x60, 0x16, 0xfa));

					//fill the smoll rectangle
					SDL_FillRect(screenSurface, &rect1, SDL_MapRGB(screenSurface->format, 0xfc, 0x17, 0x08));

					//fill the smoll rectangle 2 
					SDL_FillRect(screenSurface, &rect2, SDL_MapRGB(screenSurface->format, 0xff, 0xfb, 0x0d));

					

					//move the smoll rectangle
					if (rect1_move) {
						rect1.x++;
						rect1.y++;
						if (rect1.x+rect1.w > screenSurface->w) rect1.x = 0;
						if (rect1.y+rect1.h > screenSurface->h) rect1.y = 0;
					}




					//move the smoll rectangle
					rect2.x++;
					rect2.y++;
					if (rect2.x + rect2.w > screenSurface->w) rect2.x = 0;
					if (rect2.y + rect2.h > screenSurface->h) rect2.y = 0;
				}
				

				
				
				if (!loading_screen) {
					//Fill the surface with a color
					/*SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xf9, 0x78, 0x07));*/
					//to create a rectangle wit the renderer
					//SDL_SetRenderDrawColor(renderer, 0x4c, 0a6, 0xff, 1)

					/*SDL_FillRect(screenSurface, &PedroRect, SDL_MapRGB(screenSurface->format, 0x02, 0x92, 0x29));*/
					
					

					SDL_RenderClear(renderer);    //Wipes everything and cleans up
					
					SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

					SDL_RenderCopy(renderer, shipTexture, NULL, &shipRect);

					SDL_RenderPresent(renderer);

				}


				//Update the surface
				SDL_UpdateWindowSurface(window);



				while (SDL_PollEvent(&e) != 0) {
					//User requests quit

					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					//User presses a key
 					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)               //loading switch
						{
						case SDLK_SPACE:   //create communism
							rect1.x = 0;
							rect1.y = 0;
							rect1.w = screenSurface->w;
							rect1.h = screenSurface->h;
							
							rect1_move = false;
							break;

						case SDLK_ESCAPE:
							quit = true;
							break;

						case SDLK_g:
							loading_screen = false;
							break;


						
						default:
							break;

						}


						if (!loading_screen) {
							switch (e.key.keysym.sym)  //game switch
							{
							case SDLK_w:
								shipRect.y = shipRect.y - 25;
								break;
							case SDLK_a:
								shipRect.x -= 20;
								break;
							case SDLK_s:
								shipRect.y += 20;
								break;
							case SDLK_d:
								shipRect.x += 20;
								break;
							case SDLK_SPACE:
								shoot = true;
								break;
								
							default:
								break;

							}



						}



					}



				}
			}

		}





	}




	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	SDL_QUIT;
	IMG_Quit();

	return 0;

}