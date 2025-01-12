#include"Prog3.h"
#include<iostream>
using namespace std;


tree::tree() {}
tree::~tree() {}

void tree::add_event()//keyed on event->name;
{


	Event * obj;
	user a_user;
	int num = a_user.schedule_specify();
	if(num == 1)
	{
		obj = new demo;
		obj->schedule();
	}
	else if(num == 2)
	{
		obj = new meeting;
		obj->schedule();
	}
	else if(num == 3)
	{
		obj = new all_day;
		obj->schedule();
		//obj->duration(); //RTTI
	}
	add_event(obj);
}


void tree::add_event(Event * ptr)
{
	/*if(!root)
	{
		root = new node;
		root->set_data(ptr);
	}*/
	add_event(ptr, root);

}
void tree::add_event(Event * ptr, node * & root) //recursively add into bST
{
	if(!root)
	{
		root = new node;
		root->set_data(ptr);
		return;
	}	
	int num = root->compare(ptr);
	if(num < 0) 
		add_event(ptr, root->get_left());
	else if(num > 0) 
		add_event(ptr, root->get_right());
	else if(num == 0)
	{
		//root->set_data(ptr);
		return;
	}
	return;
}
void tree::display()
{
	display(root);
	//catch root;
	return;

}
void tree::display(node * root) //inorder
{
	if(root)
	{
		display(root->get_left());
		root->display();
		display(root->get_right());
	}
	return;
	
	throw root;
}

void tree::edit()
{	
				
}
void node::display()
{
	//loop to display list
 	for (auto const &v : a_list)
        	v->display();
	

	/*
	for (auto it = a_list.begin(); it !=a_list.end(); ++it)
	{
		*a_list.display();
	}
	*/


	
	/*for(int i = 0; i < a_list.size(); ++i)
	{
		cout << "name: " << a_list
		cout << "date: " << a_list[i].date;
	}*/
}	
node::node()
{
	//event_ptr = nullptr;
}	

node::~node() {}

void node::set_data(Event * obj)
{
	a_list.push_front(obj);
}
Event * & node::get_data() {}

node * & node::get_right()
{
	return right;
}


node * & node::get_left() 
{
	return left;
}
void node::set_left(){}

int node::compare(Event * ptr)
{
	return ptr->compare(a_list.front());
}
