#pragma once

#include<SDL.h>
#include<SDL_image.h>

class texture_maneger
{
public:
	static SDL_Texture* load_texture(const char* loc, SDL_Renderer* rend)
	{
		SDL_Surface* tempsurface = IMG_Load(loc);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, tempsurface);
		SDL_FreeSurface(tempsurface);
		return tex;
	}
};