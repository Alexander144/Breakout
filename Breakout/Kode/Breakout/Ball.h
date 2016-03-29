#ifndef BALL_H
#define BALL_H

#include "SDL.h"
#include "Game.h"
class Ball {
public:
	const float Speed = 550;


	float x;
	float y;
	
	float width;
	float height;

	float directionX;
	float directionY;

	SDL_Rect rect;

	void Step(float dt);
	void SetDirection(float newDirectionX, float newDirectionY);
	void Render(float delta);
};

#endif // !BALL_N
