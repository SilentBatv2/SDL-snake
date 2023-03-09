#include<../../Snake.hpp>

snake_head::snake_head()
	: dir{false, false}
{
}

snake_head::~snake_head()
{
}

bool *snake_head::Get_dir()
{
	return dir;
}

snake_body::snake_body(int t)
	: timer(t)
{
}

snake_body::snake_body(snake_body &sn) : Object(sn), timer(sn.timer)
{
}

void snake_body::set_timer(int time)
{
	timer = time;
}

void snake_body::update()
{
	timer--;
}

snake_body::~snake_body()
{
}

snake::snake(int* gen_lim_x, int* gen_lim_y)
	: sb_o(length), length(0), renderer(nullptr)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uid1(gen_lim_x[0], gen_lim_x[1]), uid2(gen_lim_y[0], gen_lim_y[1]), uid3(0, 3);

	int rand2 = uid2(gen), rand1 = uid1(gen), rand3 = uid3(gen);

	head.dir[0] = rand3 %2;
	head.dir[1] = (rand3 - head.dir[0]) % 2;
	head.SetVel((1-rand3/2)*((2*(rand3%2))- 1), (rand3/2)*((2 * (rand3 % 2)) - 1));
	head.SetPos(rand1, rand2);

	sb_o.SetVel(head.GetVel()[0], head.GetVel()[1]);
	sb_o.SetPos(head.GetPos()[0] - head.GetVel()[0], head.GetPos()[1] - head.GetVel()[1]);

	body.push_front(sb_o);
}

void snake::update() // update this shit
{
	sb_o.SetPos(head.GetPos()[0], head.GetPos()[1]);
	sb_o.set_timer(length);
	//sb_o.Init_Object_outloc({size_x*(sb_o.GetPos()[0]), size_y*(sb_o.GetPos()[1]), size_x, size_y});
	body.push_front(sb_o);
}

snake::~snake()
{
}