#include "Ball.h"

void Ball::Step(float dt)
{
	x += directionX * dt;
	y += directionY *dt;
}

void Ball::SetDirection(float newDirectionX, float newDirectionY)
{
	float lenght = sqrt(newDirectionX * newDirectionX + newDirectionY * newDirectionY);

	directionX = Speed * (newDirectionX/lenght);
	directionY = Speed * (newDirectionY/lenght);
}
/*
void Ball::Render(float delta)
{
	rect.x = (int)(x + 0.5f);
	rect.y = (int)(x + 0.5f);
	rect.w = width;
	rect.h = height;

	SDL_RenderCopy(rendrer.rendrer, rendrer.texture, 0, &rect);
	SDL_DestroyTexture(rendrer.texture);
}
*/