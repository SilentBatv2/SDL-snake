#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<../../Game_Objects.hpp>


class Game
{
private:


	static SDL_Window* window;
	static SDL_Renderer* renderer;
	Object* head;
	Object* body;
	Object* tail;
	Object* treat;
	bool is_running;
public:
	class Map
	{
		static int** map;
		static int rows;
		static int columns;
		bool initialized;
	public:
		Map();
		~Map();
		void Init(int row, int col);
		void free();
		
	};
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int hight, bool fullscreen);
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

};

