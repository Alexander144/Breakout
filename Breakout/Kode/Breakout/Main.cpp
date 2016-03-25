#include "Breakout.h"
#include <iostream>
#include <vector>
#include <memory>
#include "SDL.h"
using namespace std;
int main()
{
	Breakout run;
	
	run.init();
	run.loadmedia();
	
	
	//run.close();

	system("Pause");
	return EXIT_SUCCESS;
}