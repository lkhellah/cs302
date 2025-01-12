#include "Prog3.h"
#include <iostream> 
using namespace std;


//Event
Event::Event() {}
Event::~Event() {}
void Event::display()
{
	cout << "Name: " << name << endl;
	cout << "Date: " << date << endl;
}
void Event::schedule() 
{
	
	cout << "Enter the name of the person you are meeting with: (if an all all_day event, enter: self): ";
	cin >> name;
	cin.ignore(100,'\n');
	cout << "Enter the date of this event: ";
	cin >> date;
	cin.ignore(100,'\n');

}
void Event::edit() {}
int Event::compare(Event * op2)
{
	return (name.compare(op2->name));
}	
		


//demo
demo::demo() {}
demo::~demo() {}
void demo::schedule()
{
	Event::schedule();
	cout << "what class are you in: ";
	getline(cin, class_name);	

}
void demo::edit() {}
void demo::display()
{
	Event::display();
	cout << "class name: " << class_name << endl;
}


//meeting
meeting::meeting()
{}
meeting::~meeting()
{}

void meeting::schedule() 
{
	Event::schedule();
	cout << "Virtual or In Person?: ";	
	getline(cin, type);
}
void meeting::edit() {}
void meeting::display()
{
	Event::display();
	cout << "Type: " << type << endl;
}



//all_day
all_day::all_day() {}
all_day::~all_day() {}
void all_day::schedule()
{
	Event::schedule();
	cout << "where is this event: ";
	getline(cin, location);
	duration();
}
void all_day::edit() {}
void all_day::display() 
{
	Event::schedule();
	cout << "location: " << location << endl;
	cout << "duration " << time << endl; //new
}
void all_day::duration()  //new
{
	cout << "How long are you staying there: (enter a number): ";
	cin >> time;
	return;
}	





