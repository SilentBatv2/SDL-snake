#include<../../Game.hpp>
#include<../../Linked_List.hpp>
#include<iostream>


/*void print(node<int>* x)
{
	std::cout << x->get_data() << ' ';
}*/

int main(int argc, char* argv[])
{
	Game* game = new Game;
	game->init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 550, false);
	while (game->running())
	{
		game->update();
		game->render();
		SDL_Delay(800);	
		game->handle_events();
	}
	
	/*
	int c = 5;
	Linked_List<int> a;
	a.push_front(c);
	a.push_front(7);
	a.push_front(9);
	a.push_front(3);
	a.iterate_func(print, 0, INT_MAX);
	*/
	/*
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("viking", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 550, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255,0,255,127);
	SDL_Surface* tempsurface = IMG_Load("Assets/viking.png");
	SDL_Texture* playertex= SDL_CreateTextureFromSurface(renderer, tempsurface);
	SDL_FreeSurface(tempsurface);
	SDL_RenderCopy( renderer, playertex, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	*/
	return 0;

}