#include "Breakout.h"
#include <iostream>
#include <vector>
#include <memory>
#include "SDL.h"
#include "Game.h"
using namespace std;
int main()
{
	Game run;
	
	run.Init();
	run.load_BMP("1.png");
	
	
	//run.close();

	system("Pause");
	return EXIT_SUCCESS;
}