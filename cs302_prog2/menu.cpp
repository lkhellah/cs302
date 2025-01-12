#include <iostream>
#include "DLL.h"
#include "user.h"
using namespace std;



int user::menu()
{
	int num{0};
	cout << "Welcome to the races!" << endl;
	do
	{
		cout << "Choose from the following races: " << endl;
		cout << "1. Street Racing(buggy)\n";
		cout << "2. Off Road Racing (dirt bike)\n";
		cout << "3. Track Racking (super car)\n";
		cin >> num;
		cin.ignore(100,'\n');
		if(num != 1 && num != 2 && num!=3)
			cout << "Valid inputs are only: 1, 2, or 3. Try again.\n";
	}while(num != 1 && num != 2 && num!=3);

	return num;

}

int user::race()
{
	int race_type = menu();
	if(race_type == 1) //street racing (buggy)
	{
		DLL<buggy> buggy_course (1);
		buggy_course.display();	
		
	}
	if(race_type == 2) //off road racing (dirt bike)
	{
		DLL<dirt_bike> dirt_course (2);
		dirt_course.display();
	}
	if(race_type == 3)
	{
		DLL<super_car> super_course (3);
		super_course.display();
	}
	
	return 0;
}
		
