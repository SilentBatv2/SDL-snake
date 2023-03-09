#include<../../Game.hpp>
#include<../../Linked_List.hpp>
#include<iostream>


/*void print(node<int>* x)
{
	std::cout << x->get_data() << ' ';
}*/

int main(int argc, char* argv[])
{
	// no need for pointer based allocation. just create the object on stack
	Game game; /*= new Game;*/
	game.init("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 550, false);
	while (game.running())
	{
		game.update();
		game.render();
		SDL_Delay(200);	
		game.handle_events();
	}
	
	return 0;

}