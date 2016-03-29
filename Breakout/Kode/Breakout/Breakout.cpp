#include "Breakout.h"
#include <iostream>
#include <string>
#include "Ball.h"
#include "PlayingField.h"

	using namespace std;
	Ball ball;
	PlayingField field;

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

	HelloWorld = IMG_Load("/Resource Files/Picture/paddleBounds.png");
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

void Breakout::CheckBallHit()
{
	if (ball.y < field.y) {
		
		ball.y = field.y;
		ball.directionY *= -1;

	}
	else if (ball.y + ball.height > field.y + field.height) {
		ball.y = field.y + field.height - ball.height;
		ball.directionY *= -1;
	}
	if (ball.x <= field.x) {
		ball.y = field.y + field.height / 2.0f - ball.height / 2.0f;
		ball.SetDirection(-1, -1);
	}
	else if (ball.x + ball.height >= field.x + field.width) {
		ball.y = field.y + field.height / 2.0f - ball.height / 2.0f;
		ball.SetDirection(1,-1);
	}
}
