#pragma once

class Object
{
protected:
	SDL_Texture* texture[2];
	const SDL_FRect* srcrect;
	SDL_FRect* dstrect;
public:
	Object()
	{
		texture[0] = nullptr;
		texture[1] = nullptr;
		srcrect = nullptr;
		dstrect = nullptr;
	}
};

class snake
{
	Object head;
	Object tail;
	Object body;
};

class Treat
{
	Object treat;
	static int spawn;
};