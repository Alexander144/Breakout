#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "PlayingField.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_>
class Game {
public:
	SDL_Window *window = nullptr;
	SDL_Renderer *rendrer;
	SDL_Surface *ScreenSurface = nullptr;
	SDL_Surface *loadImage;
	SDL_Surface *optimizeImage;
	SDL_Texture *texture;
	SDL_Event Event;
	SDL_GLContext context;

	SDL_Surface *load_image(std::string filename);

	SDL_Surface * load_BMP(std::string filename);
	
	bool ApplayingImage();

	bool key_left = false;
	bool key_right = false;

	int SCREEN_WIDTH = 300;
	int SCREEN_HEIGHT = 200;

	unsigned int lastTick;
	unsigned int FPStick;
	int fps;
	int frameCount;

	//Ball *ball;
	//PlayingField *field;
	//void Render(float delta);
	bool Init();
};

#endif // !GAME_H

