#pragma once

class Object
{
protected:
	//SDL_Texture* texture;
	//SDL_Rect* srcrect;
	//SDL_Rect* dstrect;
	int pos[2];
	int vel[2];
	//bool* initialized;
	//void update_dest(int x_scale, int y_scale);
public:
	Object();
	Object(Object&obj);
	//Object(SDL_Rect srcrec);
	~Object();

	//void Init_Object(const char* loc, SDL_Renderer* rend);
	//void Init_Object_outloc(SDL_Rect recto);  // meant to be called in game.cpp
	//SDL_Texture* Get_Texture();
	//SDL_Rect* Get_SrcRect();
	//SDL_Rect* Get_DstRect();
	void SetPos(int xpos, int ypos);
	void SetVel(int xvel, int yvel);
	void update_pos();
	int* GetPos();
	int* GetVel();
	//void clear();
};

class Treat
{
	Object treat;
	int spawn;
};