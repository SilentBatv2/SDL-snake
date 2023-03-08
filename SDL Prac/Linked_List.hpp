#pragma once
#include<SDL.h>

template<typename typ>
class node 
{
	typ dat;
	node* last;
	node* next;
public:
	node()
	{
		last = nullptr;
		next = nullptr;
	}
	node(typ &data) : dat(data)
	{
		last = nullptr;
		next = nullptr;
	}
	~node()
	{

	}
	void set_last(node* &point)
	{
		last = point;
	}
	node *get_last()
	{
		return last;
	}
	void set_next(node*& point)
	{
		next = point;
	}
	node* get_next()
	{
		return next;
	}
	typ get_data()
	{
		return dat;
	}
	void set_data(typ &data)
	{
		dat = data;
	}
};


template<typename typ>
class Linked_List
{
	node<typ>* beg;
	node<typ>* end;
	int no_of_elements;
public:
	Linked_List()
	{
		no_of_elements = 0;
		beg = nullptr;
		end = nullptr;
	}
	void push_front(typ &dat)
	{
		if (no_of_elements == 0)
		{
			beg = new node<typ>(dat);
			end = beg;
		}
		else
		{
			node<typ>* temp = beg;
			beg = new node<typ>(dat);
			beg->set_next(temp);
			temp->set_last(beg);
		}
		++no_of_elements;
	}
	void pop_back()
	{
		if (no_of_elements > 0)
		{
			node<typ>* temp = end->get_last();
			delete end;
			end = temp;
			if (no_of_elements == 1)
			{
				beg = nullptr;
			}
			--no_of_elements;
		}
	}
	void iterate_func(void (*func)(node<typ>*), int beg_index, int ending_index)
	{
		node<typ>* curr = beg;
		if ((ending_index < no_of_elements) && (beg_index >= 0))
		{
			for (int i = 0; i < beg_index; ++i)
			{
				curr = curr->get_next();
			}
			for (int i = beg_index; i < ending_index; ++i)
			{
				func(curr);
				curr = curr->get_next();
			}
		}
		else
		{
			for (int i = 0; i < no_of_elements; ++i)
			{
				func(curr);
				curr = curr->get_next();
			}
		}
	}
	void iter_func_rev(void(*func)(node<typ>*&, SDL_Renderer*&), int beg_index, int ending_index, SDL_Renderer* rend)
	{
		node<typ>* curr = end;
		if ((beg_index < no_of_elements) && (ending_index > 0))
		{
			for (int i = no_of_elements; i > beg_index + 1; --i)
			{
				curr = curr->get_last();
			}
			for (int i = beg_index; i > ending_index; --i)
			{
				func(curr, rend);
				curr = curr->get_last();
			}
		}
		else
		{
			for (int i = no_of_elements; i > 0; --i)
			{
				func(curr, rend);
				curr = curr->get_last();
			}
		}
	}
	
	void clear()
	{
		node<typ>* temp1 = beg, *temp2;
		for (int i = 0; i < no_of_elements; ++i)
		{
			temp2 = temp1->get_next();
			delete temp1;
			temp1 = temp2;
		}
		beg = nullptr;
		end = nullptr;
		no_of_elements = 0;
	}
	node<typ>* front()
	{
		return beg;
	}
	node<typ>* ret_iter(int iter)
	{
		node<typ>* point = beg;
		if (iter < no_of_elements)
		{
			for (int i = 0; i < iter; ++i)
			{
				point = point->get_next();
			}
			return point;
		}
		else
			return nullptr;
	}
	node<typ>* back()
	{
		return end;
	}
	void is_clear()
	{
		return no_of_elements == 0;
	}
	~Linked_List()
	{
		clear();
	}
};