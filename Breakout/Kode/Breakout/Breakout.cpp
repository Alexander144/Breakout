#include "Breakout.h"
#include <iostream>
#include <string>

bool Breakout::init()
{
	bool success = true;
	int SCREEN_WIDTH = 300;
	int SCREEN_HEIGHT = 200;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//lager et vindu
		Window = SDL_CreateWindow("Breakout",
								  SDL_WINDOWPOS_UNDEFINED,
								  SDL_WINDOWPOS_UNDEFINED,
								  SCREEN_HEIGHT,
								  SCREEN_WIDTH,
								  SDL_WINDOW_SHOWN);

		if(Window == nullptr)
		{
			printf("Window could not be created! SDL_ERROR: %s\n",SDL_GetError());
			success = false;
		}
		else
		{
			ScreenSurface = SDL_GetWindowSurface(Window);
		}

	}
	return success;
}

bool Breakout::loadmedia()
{
	bool success = true;

	HelloWorld = SDL_LoadBMP("/Resource Files/Picture/e.bmp");
	if(HelloWorld == nullptr)
	{
		printf("Could not load image %s SDL ERROR: %s", "e.bmp",SDL_GetError());
		success = false;
	}
	SDL_BlitSurface( HelloWorld, nullptr, ScreenSurface, nullptr );
	SDL_UpdateWindowSurface(Window );
	return success;
}

void Breakout::close()
{
	SDL_FreeSurface( HelloWorld );
	HelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow( Window );
	Window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
