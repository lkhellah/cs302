#include<string>
using namespace std;

//Program 2
//Layaal Khellah
//CS 302 winter 2023

//header file that include 3 vehicles with 
//their base vehicle class



class vehicle //base
{

	public:
		vehicle();
		~vehicle();
		bool add_speed(int);
		bool add_age(int);
		

	protected:
		//course a_course;
		int speed;
		int age;	
		

};



class buggy: public vehicle
{

	public:
		buggy();
		~buggy();
		int display();
		int add_turbo(int);
		//overload assignment operator
	
	private:
		int turbo_mode;	

};


class dirt_bike: public vehicle
{

	public:
		dirt_bike();
		~dirt_bike();
		int strength(int);

	private:
		int tire_strength;

};


class super_car: public vehicle
{

	public:
		super_car();
		~super_car();
		int gas(string);

	private:
		string gas_quality;


};
