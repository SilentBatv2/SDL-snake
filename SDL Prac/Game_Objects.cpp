#pragma once

#include<../../Game_Objects.hpp>

Object::Object() 
	: pos{ 0,0 }, vel{0, 0}
{
}


Object::Object(Object &obj)
	: pos{ obj.pos[0], obj.pos[1] }, vel{obj.vel[0], obj.vel[1]}
{
}

/*Object::Object(SDL_Rect srcrec)
{
	initialized = new bool(false);
	texture = nullptr;
	srcrect = new SDL_Rect(srcrec);  // TODO : ADD A way to change srcrec while running for the same srcrec object. Its easy but im lazy :).
	dstrect = nullptr;
	pos = nullptr;
	vel = nullptr;
}*/

Object::~Object()
{
	//delete[] pos;
	//delete[] vel;
}

/*void Object::Init_Object(const char* loc, SDL_Renderer* rend)
{
	if (texture = texture_maneger::load_texture(loc, rend))
	{
		pos = new int[2];
		pos[0] = 0;
		pos[1] = 0;
		vel = new int[2];
		vel[0] = 0;
		vel[1] = 0;
		*initialized = true;
	}
	else
	{
		*initialized = false;
	}
}*/

/*
void Object::Init_Object_outloc(SDL_Rect rectO)
{
	if (dstrect == nullptr)
	{
		dstrect = new SDL_Rect;
	}
	*dstrect = rectO;
}*/

/*SDL_Texture* Object::Get_Texture()
{
	return texture;
}*/

/*SDL_Rect* Object::Get_SrcRect()
{
	return srcrect;
}*/

/*
SDL_Rect* Object::Get_DstRect()
{
	return dstrect;
}*/

void Object::SetPos(int xpos, int ypos)
{
	pos[0] = xpos;
	pos[1] = ypos;
}

void Object::SetVel(int xvel, int yvel)
{
	vel[0] = xvel;
	vel[1] = yvel;
}

void Object::update_pos()
{
	pos[0] += vel[0];
	pos[1] += vel[1];
}

/*void Object::update_dest(int x_scale, int y_scale)
{
	(*dstrect).x = pos[0]*x_scale;
	(*dstrect).y = pos[1]*y_scale;
}*/

int* Object::GetPos()
{
	return pos;
}

int* Object::GetVel()
{
	return vel;
}

/*
void Object::clear()
{
	if (*initialized)
	{
		delete[] pos;
		delete[] vel;
		SDL_DestroyTexture(texture);
		*initialized = false;
	}
}*/