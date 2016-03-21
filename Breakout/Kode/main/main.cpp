#include <iostream>
#include <SDL.h>
// NB: Denne koden tar seg IKKE av feilhåndtering ved init.
int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO); // Init. SDL2
	SDL_Window* window = NULL; // Pointer to Window
							   // Lag et vindu med gitte settings
							   // For alle mulige konfigurasjonsalternativer, se: http://goo.gl/8vDJN
	window = SDL_CreateWindow(
		"Et awesome SDL2-vindu!", // window title
		SDL_WINDOWPOS_UNDEFINED, // initial x position
		SDL_WINDOWPOS_UNDEFINED, // initial y position
		550, // width, in pixels
		400, // height, in pixels
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL // flags
		);
	

	SDL_Delay(10000); // Pause i 3 sekunder, lukk vinduet
	SDL_DestroyWindow(window);
	SDL_Quit(); // Be SDL om å rydde opp
	return EXIT_SUCCESS;
}