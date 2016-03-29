#ifndef PLAYERFIELD_H
#define PLAYERFIELD_H


#include "SDL.h"
#include "Game.h"
class PlayingField {
public:
	float x;
	float y;
	SDL_Rect rect;

	//Game rendrer;
	float width;
	float height;
	void Render(float delta);
};

#endif // !PLAYERFIELD_H

