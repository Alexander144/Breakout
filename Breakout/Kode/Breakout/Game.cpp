#include "Game.h"
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengles2.h>
#include <stdio.h>

Game::Game()
{
}

Game::~Game()
{
	//Deallocate surface
	SDL_FreeSurface(image);
	image = nullptr;

	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

bool Game::Init(const int height, const int width)
{
	SCREEN_HEIGHT = height;
	SCREEN_WIDTH = width;
	//Initialization flag
	bool success = true;
	
	
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		//Create rendrer for window
		render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			screen = SDL_GetWindowSurface(window);
		}
	}

	return success;
}

bool Game::LoadMedia(std::string filename)
{
	//Loading success flag
	bool success = true;

	SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

	texture = loadTexture("Picture/Texture.png");
	int imgFlags = IMG_INIT_PNG;
	
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("Unable to load image %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
		success = false;
	}
	else {
		image = loadSurface(filename.c_str());
	}

	return success;
}

SDL_Surface* Game::loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screen->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

SDL_Texture* Game::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(render, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

bool Game::DisplayMedia()
{
	//Apply the image stretched
	SDL_Rect stretchRect;
	stretchRect.x = 100;
	stretchRect.y = 150;
	


	//Apply the image
	SDL_BlitSurface(image, NULL, screen, &stretchRect);
	//Update the surface
	SDL_UpdateWindowSurface(window);
	return true;
}

bool Game::Setup()
{
	bool success = true;
	if (!Init(600, 900)) {
		std::cout << "Failed to initiialize" << std::endl;
		success = false;
	}
	else {
		if (!LoadMedia("Picture/Paddle.png")) {
			std::cout << "Failed to initiialize" << std::endl;
			success = false;
		}
		else {
			//DisplayMedia();
		}
	}
	DrawBox();
	
	MakeViewPort();

	SDL_RenderPresent(render);
	/*
	SDL_RenderClear(render);
	SDL_RenderCopy(render,texture, NULL, NULL);
	SDL_RenderPresent(render);*/

	return success;
	
}

void Game::MakeViewPort()
{
	SDL_Rect topViewPort;
	topViewPort.x = 0;
	topViewPort.y = 0;
	topViewPort.w = SCREEN_WIDTH;
	topViewPort.h = SCREEN_HEIGHT / 6;
	SDL_RenderSetViewport(render, &topViewPort);

	SDL_RenderCopy(render, texture, NULL, NULL);
}

void Game::DrawBox()
{
	SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(render);

	SDL_Rect fillrect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	SDL_SetRenderDrawColor(render, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(render, &fillrect);

	SDL_Rect outlineRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	SDL_SetRenderDrawColor(render, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawRect(render, &outlineRect);

	SDL_SetRenderDrawColor(render, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderDrawLine(render, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

	SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0x00, 0xFF);

	for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
		SDL_RenderDrawPoint(render, SCREEN_WIDTH / 2, i);
	}
}


