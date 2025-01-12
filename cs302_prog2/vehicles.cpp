#include "vehicles.h"
#include <iostream>
#include <cstring>
using namespace std;


//creating the course based off of the string entered
/*
course & course::operator =(const string add, int value)
{
	if(value == 1)
	{
		one = add;
		return (*this);
	}
	if(value == 2)
	{
		two =  add;
		return (*this);
	}
	if (value == 3)
	{
		three = add;
		return (*this);	
	}
	if(value == 4)
	{
		four = add;
		return (*this);
	}
}
*/	
	

vehicle::vehicle()
{
	speed = 0;
	age = 0;
}

vehicle::~vehicle()
{
	speed = 0;
	age = 0;
}


bool vehicle::add_speed(int add_speed)
{
	if(isdigit(add_speed))
	{
		if(add_speed > speed)
			cout << "speed is now greater: " << add_speed << endl;
		else if(add_speed < speed)
			cout << "speed is now less: " << add_speed << endl;
		speed = add_speed;
		return true;
	}
	else
	{
		cout << "NUMBERS are the only valid input..." << endl;
		return false;		
	}

}

bool vehicle::add_age(int add_age)
{
	if(isdigit(add_age))
	{
		if(add_age > age)
			cout << "age is now greater than before: " << add_age << endl;
		else if(add_age < age)
			cout << "age is now less than before: " << add_age << endl;
		age = add_age;
		return true;
	}
	else
	{
		cout << "NUMBERS are only valid input ..." << endl;
		return false;
	}
}




buggy::buggy()
{ 
	turbo_mode = 0;
}

buggy::~buggy()
{
	turbo_mode = 0;
}

int buggy::display()
{
	cout << "turbo mode level is at: " << turbo_mode << endl;
	return 1;
}


int buggy::add_turbo(int add_turbo_mode)
{
	
	if(isdigit(add_turbo_mode))
	{
		if(add_turbo_mode > turbo_mode)
			cout << "turbo mode is now greater: " << add_turbo_mode<< endl;
		else if(add_turbo_mode < turbo_mode)
			cout << "turbo mode is now less: " << add_turbo_mode << endl;
		turbo_mode = add_turbo_mode;
		return true;
	}
	else
	{
		cout << "NUMBERS are the only valid input..." << endl;
		return false;		
	}

}



dirt_bike::dirt_bike()
{
	tire_strength = 0;
}

dirt_bike::~dirt_bike()
{
	tire_strength = 0;
}

int dirt_bike::strength(int change_strength)
{
	
	if(isdigit(change_strength))
	{
		if(change_strength > tire_strength)
			cout << "tire strength is now greater: " << change_strength << endl;
		else if(change_strength < tire_strength)
			cout << "tire strength is now less: " << change_strength << endl;
		tire_strength = change_strength;
		return true;
	}
	else
	{
		cout << "NUMBERS are the only valid input..." << endl;
		return false;		
	}
}


super_car::super_car()
{
	gas_quality = " ";
}


super_car::~super_car()
{
	gas_quality.clear();
}

int super_car::gas(string change_gas)
{
	cout << "Gas quality is now: " << change_gas << endl;
	gas_quality = change_gas;
	return 1;

}
