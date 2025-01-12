#include "Prog3.h"
#include <iostream>
using namespace std;

int user::menu()
{
	int num {0};
	cout << "Hello. Welcome to your schedule organizer\n";
	do
	{
		cout << "\nChoose from the following options:\n"
		     << "0) Quit\n"
		     << "1) Schedule an event\n"
		     << "2) Edit an event\n"
		     << "3) Display all events\n"
		     << "4) Delete an event\n";
		cin >> num;
		cin.ignore(100,'\n');
		if(num!= 0 && num != 1 && num !=2 && num !=3 && num!=4)
			cout << "Error. Valid input is 0,1,2,3,4," << endl;
	} while(num != 0 && num != 1 && num !=2 && num !=3 && num!=4);

	return num;
}	
int user::schedule_specify() //specify which meeting to schedule
{
	int num{0};
	do			
	{
		cout << "schedule a 1) demo, 2) regular meeting, 3) all day event: ";
		cin >> num;
		cin.ignore(100,'\n');
		if(num!= 1 && num!=2 && num !=3)
			cout << "Error. Valid input is 1,2,3" << endl;
	}while(num != 1 && num !=2 && num !=3);
	return num;
}

