#pragma once
#include<../../Linked_List.hpp>
#include<../../Game_Objects.hpp>
#include<random>

class snake_head : public Object
{
protected:
	bool* dir;
public:
	snake_head();
	~snake_head();
	bool* Get_dir();
	friend class snake;
};

class snake_body : public Object
{
protected:
	int* timer;
public:
	snake_body(int t);
	snake_body(snake_body &sn);
	~snake_body();
	void set_timer(int time);
	void update();
	friend class snake;
};

class snake
{
protected:
	snake_head* head;
	snake_body* sb_o;
	Linked_List<snake_body> body;
	int* length;
	SDL_Renderer* renderer;
public:
	snake(int* gen_lim_x, int* gen_lim_y);
	void update();
	~snake();
	friend class Game;
};
