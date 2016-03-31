#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "PlayingField.h"

#include <string>
#include <iostream>

class Game {
public:
	Game();
	~Game();
	bool Init(const int height, const int width);
	bool LoadMedia(std::string filename);
	bool DisplayMedia();
	bool Setup();

	void MakeViewPort();
	void DrawBox();
	
	SDL_Surface* loadSurface(std::string path);

	SDL_Texture * loadTexture(std::string path);

private:
	SDL_Window *window = nullptr;
	SDL_GLContext context = nullptr;
	SDL_Renderer *render = nullptr;
	SDL_Texture *texture = nullptr;
	SDL_Surface *image = nullptr;
	SDL_Surface *screen = nullptr;
	//Screen attributes
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	const int SCREEN_BPP = 32;


};

#endif 

