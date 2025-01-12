#include<iostream>
#include"Prog3.h"

int main()
{
	user a_user;
	int choice = a_user.menu();
	tree a_tree;
	do
	{
		if(choice == 0)
		{
			cout << "Goodbye!" << endl;
			return 0;
		}
		if(choice == 1)
		{
			a_tree.add_event();
		}	
		if (choice == 2)
		{
			//a_tree.edit();
		}	
		if(choice == 3)
		{
			a_tree.display();
		}
		choice = a_user.menu();
	}while(choice !=0);

	//RTTI test
	/*
	all_day obj;
	Event * all_day_ptr = &obj; //upcastingA
	all_day * day;
	day = dynamic_cast<all_day *>(all_day_ptr);
	day->duration();
	*/
	

	return 0;
}

