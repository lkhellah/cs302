#include <cstring>

using std::string;

//menu class
//race track calls menu to figure out which track user wants
//three different tracks created, corresponding to car

//buggy has a street 
//dirt road has an off_road
//super car has a track
//meant to tell DLL which type of race to make


class user
{
	public:
		int menu();
		int race();
	private:
};
/*
class course
{
	public:
		//course & operator=(string add, int value);
	private:
		string one;
		string two;
		string three;
		string four;
		string five;
};
*/
/*
class street
{
	//node in DLL has a "terrain" data member that each 
	//string corresponds to. the node will alternate 
	//terrains, meaning one two and three will be used 
	//repeatedly for street race
	//string one and four are easy, two and three and five are hard
	string one = "clear";
	string two = "bumpy"; 
	string three = "pedestrians";
	string four = "flat";
	string five = "pot hole";
};

struct off_road
{
	//same concept as street 
	//one,three, four are hard
	//two,five are easy
	string one = "dusty/unclear vision";
	string two = "clear";
	string three = "bumpy";
	string four = "pot hole";
	string five = "flat";

};
struct track 
{
	//three and four hard
	string one = "straight";
	string two = "bend";
	string three = "dirt";
	string four = "bump";
	string five = "flat";

};
*/
