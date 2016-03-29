#include "Game.h"

bool Game::Init()
{
	bool success = true;


	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//lager et vindu
		window = SDL_CreateWindow("Breakout",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_HEIGHT,
			SCREEN_WIDTH,
			SDL_WINDOW_OPENGL |
			SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			ScreenSurface = SDL_GetWindowSurface(window);
		}

	}
	return success;
}

SDL_Surface * Game::load_image(std::string filename)
{
	loadImage = nullptr;

	optimizeImage = nullptr;

	loadImage = IMG_Load(filename.c_str());

	if (loadImage != nullptr) {

		optimizeImage = SDL_ConvertSurface(loadImage, ScreenSurface->format, NULL);

		SDL_FreeSurface(loadImage);
	}
	else {
		printf("Not Valid filePath");
	}

	return optimizeImage;
}
SDL_Surface * Game::load_BMP(std::string filename)
{
	loadImage = nullptr;

	optimizeImage = nullptr;

	loadImage = SDL_LoadBMP("example.bmp");

	context = SDL_GL_CreateContext(window);

	if (loadImage != nullptr) {

		glEnable(GL_TEXTURE_2D);
		GLuint texture;

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, loadImage->format->BytesPerPixel, loadImage->w, loadImage->h,0,GL_RGB,GL_UNSIGNED_BYTE, loadImage->pixels);
		
	}
	else {
		printf("Not Valid filePath");
	}
		SDL_FreeSurface(loadImage);
		SDL_GL_DeleteContext(context);
	return loadImage;
}
/*
void Game::Render(float delta)
{
	SDL_SetRenderDrawColor(rendrer, 0, 0, 0, 255);
	SDL_RenderClear(rendrer);

	field->Render(delta);
	ball->Render(delta);

	SDL_RenderPresent(rendrer);

	surface = IMG_Load("/Resource Files / Picture / paddleBounds.png");
	texture = SDL_CreateTextureFromSurface(rendrer, surface);
	SDL_FreeSurface(surface);

}*/

