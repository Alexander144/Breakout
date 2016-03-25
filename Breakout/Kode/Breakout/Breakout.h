#ifndef BREAKOUT_H
#define BREKOUT_H
#include "SDL.h"
#undef main

class Breakout
{
public:
	//Vindu vi rendrer til
	SDL_Window *Window = nullptr;

	//surface er område som er inne i vinduet
	SDL_Surface *ScreenSurface = nullptr;

	//bilde viser seg på bilde
	struct SDL_Surface *HelloWorld = nullptr;
	bool init();
	bool loadmedia();
	void close();

private:
};
#endif
