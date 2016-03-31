#include "Breakout.h"
#include <iostream>
#include <vector>
#include <memory>
#include "SDL.h"
#include "Game.h"
#include <GL/glew.h>
#include "windows.h"
#include <GL/gl.h> 
#include <GL/glu.h> 

using namespace std;
int main()
{
	Game run;
	bool quit = false;

	SDL_Event e;

	run.Setup();
	system("Pause");
	return EXIT_SUCCESS;
}