#include "PlayingField.h"

void PlayingField::Render(float delta)
{
	rect.x = (int)(x + 0.5f);
	rect.y = (int)(x + 0.5f);
	rect.w = width;
	rect.h = height;

	//SDL_RenderCopy(rendrer.rendrer, rendrer.texture, 0, &rect);
	//SDL_DestroyTexture(rendrer.texture);
}
