#pragma once

#include<iostream>
#include<../../Texture_maneger.cpp>
#include<../../Snake.hpp>

enum Obj_typ
{
	HEAD, BODY, TREAT
};

// in c++ classes can not be static, their instances or members can be
class Game
{
private:
	SDL_Window* window;
	static int win_width;
	static int win_hight;
	int treatpos[2];
	SDL_Renderer* renderer;
	static SDL_Texture* head;
	static SDL_Texture* body;
	static SDL_Texture* treat;
	snake* Sn;
	bool is_running;
	void set_treat_pos();
	bool check_treat();
public:
	class Map
	{
		static int rows;
		static int columns;
		static bool initialized;
		static SDL_Rect rect;
	public:
		Map();
		~Map();
		static void Init(int row, int col);
		static void free();
		static int get_row();
		static int get_columns();
		static SDL_Rect get_rect(int* pos, int x_scale, int y_scale);
	};
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int hight, bool fullscreen);
	static SDL_Texture* get_texture(Obj_typ);
	void handle_events();
	void update();
	void render();
	void clean();
	bool running()
	{
		return is_running;
	}
private:
	Map game_map;
	//void Render_body(node<snake_body>* sn);
	//SDL_DisplayMode DM;
};
