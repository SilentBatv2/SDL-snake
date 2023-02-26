#include<../../Game.hpp>

Game::Map::Map()
{
	map = nullptr;
	rows = 0;
	columns = 0;
	initialized = false;
}

Game::Map::~Map()
{
	if (initialized)
	{
		free();
	}
}

void Game::Map::Init(int row, int col)
{
	columns = col;
	rows = row;
	map = new int* [row];
	for (int i = 0; i < row; ++i)
	{
		map[i] = new int[col];
		for (int j = 0; j < col; ++j)
		{
			map[i][j] = 0;
		}
	}
	initialized = true;
}

void Game::Map::free()
{
	{
		for (int i = 0; i < rows; ++i)
		{
			delete[] map[i];
		}
		delete map;
		initialized = false;
	}
}

Game::Game()
{
window = nullptr;
renderer = nullptr;
is_running = false;
}

Game::~Game()
{
	if (is_running)
	{
		clean();
	}
}

bool Game::init(const char* title, int xpos, int ypos, int width, int hight, bool fullscreen)
{
	int flag = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "subsystems initialized.\n";
		window = SDL_CreateWindow(title, xpos, ypos, width, hight, flag);
		if (window)
		{
			std::cout << "window created.\n";
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 126);
			std::cout << "renderer initialized\n";
		}
		is_running = true;
		game_map.Init(25, 20);
		SDL_Surface* tempsurface = IMG_Load("Assets/vikingstand.png");
		SDL_Texture* playertex = SDL_CreateTextureFromSurface(renderer, tempsurface);
		return true;
		
	}
	else
	{
		is_running = false;
		return false;
	}

}

void Game::handle_events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		clean();
		is_running = false;
		break;
	}
}
void Game::update()
{

}

void Game::render()
{
	SDL_RenderClear(renderer);
	//update secoundry display buffer
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	is_running = false;
	std::cout << "closed all subsystems.\n";
}
