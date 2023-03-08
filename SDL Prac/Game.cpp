#include<../../Game.hpp>

#define TILE_X_SIZE (Game::win_width / Game::Map::get_row())
#define TILE_Y_SIZE (Game::win_hight / Game::Map::get_columns())
#define SPAWN_IN_X 5
#define SPAWN_IN_Y 3
#define GRID_IN_X 25
#define GRID_IN_Y 20

int Game::win_hight = 0;
int Game::win_width = 0;
SDL_Texture* Game::head = nullptr;
SDL_Texture* Game::body = nullptr;
SDL_Texture* Game::treat = nullptr;
//int** Game::Map::map = nullptr;
int Game::Map::rows = 0;
int Game::Map::columns = 0;
bool Game::Map::initialized = false;
SDL_Rect* Game::Map::rect = nullptr;

Game::Map::Map()
{
	//map = nullptr;
	rect = nullptr;
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
	rect = new SDL_Rect;
	columns = col;
	rows = row;
	/*map = new int* [row];
	for (int i = 0; i < row; ++i)
	{
		map[i] = new int[col];
		for (int j = 0; j < col; ++j)
		{
			map[i][j] = 0;
		}
	}*/
	initialized = true;
}

SDL_Rect* Game::Map::get_rect(int* pos, int x_scale = TILE_X_SIZE, int y_scale = TILE_Y_SIZE)
{
	*rect = {pos[0]*x_scale, pos[1]*y_scale, x_scale, y_scale};
	return rect;
}

void Game::Map::free()
{
	{
		/*for (int i = 0; i < rows; ++i)
		{
			delete[] map[i];
		}
		delete map;*/
		initialized = false;
	}
}

int Game::Map::get_row()
{
	return rows;
}

int Game::Map::get_columns()
{
	return columns;
}

Game::Game()
{
	window = nullptr;
	renderer = nullptr;
	is_running = false;
	win_hight = 0;
	win_width = 0;
	Sn = nullptr;
	treatpos = nullptr;
}

Game::~Game()
{
	if (is_running)
	{
		clean();
	}
}

void Render_body(node<snake_body>* &sn, SDL_Renderer* &rend)
{
	SDL_RenderCopy(rend, Game::get_texture(BODY), nullptr, Game::Map::get_rect(sn->get_data().GetPos()));
	/*if (update)
	{
		sn->get_data().update();
	}*/
}

bool Game::init(const char* title, int xpos, int ypos, int width, int hight, bool fullscreen)
{
	treatpos = new int[2];
	set_treat_pos();
	win_hight = hight;
	win_width = width;
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
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "renderer initialized\n";
		}
		is_running = true;
		head = texture_maneger::load_texture("Assets/Blue.png", renderer);
		body = texture_maneger::load_texture("Assets/Green.png", renderer);
		treat = texture_maneger::load_texture("Assets/Red.png", renderer);
		game_map.Init(GRID_IN_X, GRID_IN_Y);
		int* a = new int[2] { (GRID_IN_X)/2 - SPAWN_IN_X, (GRID_IN_X)/2 + SPAWN_IN_X }, * b = new int[2] {(GRID_IN_Y)/2 - SPAWN_IN_Y, (GRID_IN_Y)/2 + SPAWN_IN_Y};
		Sn = new snake(a, b);
		delete[] a;
		delete[] b;
		/*red = new Object;
		red->Init_Object("Assets/Red.png", renderer);
		red->SetPos(3, 0);
		red->SetVel(1, 0);
		red->Init_Object_outloc(a);
		*/
		return true;
		
	}
	else
	{
		is_running = false;
		return false;
	}

}

SDL_Texture* Game::get_texture(Obj_typ obj)
{
	switch (obj)
	{
	case HEAD:
		return head;
	case BODY:
		return body;
	case TREAT:
		return treat;
	}
	return nullptr;
}

void Game::handle_events()
{
	SDL_Event event;
	bool key_press = true;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			clean();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_DOWN:
				
				if (key_press)
				{
					if (Sn->head->GetVel()[1] != -1)
					{
						Sn->head->SetVel(0, 1);
					}
				}
				key_press = false;
				break;
			case SDLK_UP:
				if (key_press)
				{
					if (Sn->head->GetVel()[1] != 1)
					{
						Sn->head->SetVel(0, -1);
					}
				}
				key_press = false;
				break;
			case SDLK_RIGHT:
				if (key_press)
				{
					if (Sn->head->GetVel()[0] != -1)
					{
						Sn->head->SetVel(1, 0);
					}
				}
				key_press = false;
				break;
			case SDLK_LEFT:
				if (key_press)
				{
					if (Sn->head->GetVel()[0] != 1)
					{
						Sn->head->SetVel(-1, 0);
					}
				}
				key_press = false;
				break;
			}
			break;
		}
	}
}
void Game::update()
{
	Sn->update();
	Sn->head->update_pos();
	if (check_treat())
	{
		Sn->body.pop_back();
	}
}

void Game::set_treat_pos()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uid1(0, GRID_IN_X), uid2(0, GRID_IN_Y);
	int rand1 = uid1(gen), rand2 = uid2(gen);
	treatpos[0] = rand1;
	treatpos[1] = rand2;
}

bool Game::check_treat()
{
	if (Sn->head->GetPos()[0] == treatpos[0] && Sn->head->GetPos()[1] == treatpos[1])
	{
		set_treat_pos();
		return false;
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Game::get_texture(HEAD), nullptr, Game::Map::get_rect(Sn->head->GetPos()));
	SDL_RenderCopy(renderer, Game::get_texture(TREAT), nullptr, Game::Map::get_rect(treatpos));

	Sn->body.iter_func_rev(Render_body, INT_MAX, INT_MIN, renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(head);
	SDL_DestroyTexture(body);
	SDL_DestroyTexture(treat);
	SDL_Quit();
	is_running = false;
	std::cout << "closed all subsystems.\n";
	delete Sn;
	delete[] treatpos;
}
