#include<string>
#include<list>
#include<memory>
using namespace std;
#include<cstring>
//Event is the Abstract Base Class
//ABC's are used when we don't need to create an object of a base class explicitly
//and when implementing the member functions in the base class doesn't make sense

class user
{
	public:
		int menu();
		int schedule_specify();
};
class Event
{
	//push up the common which is: need  to  be  scheduled,  maybe  deleted  
	//if  the  event  no  longer  makes  sense, edited, and displayed. 

	public:
		Event();
		virtual ~Event();
		virtual void schedule();
		virtual void edit();
		virtual void display();
		int compare(Event * op2);

	private:
		string name;
		string date;
};


//Proficiency demos are scheduled in parallel, so there are multiple overlapping appointments with staggered start and stop times.
class demo: public Event
{
	public:
		demo();
		~demo();
		void schedule();
		void edit();
		void display();
	private:
		string class_name;
		
};
//regular meetings one person at a time, no overlap, break before next meeting
class meeting:public Event
{

	public:
		meeting();
		~meeting();
		void schedule();
		void edit();
		void display();
		
	private:
		string type; //virtual in person
};


//All day appointments do not have a start and stop time
//provide functionality of location, duration, expect to arrive back
class all_day: public Event
{
	public:
		all_day();
		~all_day();
		void schedule();
		void edit();
		void display();
		void duration ();
	private:
		string location; //prompt in schedule
		int time; //for duration RTTI function
		
};	

class node //for tree
{
	public:
		node();
		~node();
		node(Event * event);
		void set_data(Event * obj);
		Event * & get_data();
		node * & get_left();
		node * & get_right();
		void set_left();
		int compare(Event * ptr);
		void display();
		//operator ==
		
	private:
		//Event * event_ptr; //to use dynamic binding and turn it into a specific event?
		node * left;
		node * right;
		std::list<Event *> a_list;
};
	

class tree //BST
{
	public:
		tree();
		~tree();
		void add_event();
		void add_event(Event * ptr);
		void add_event(Event * ptr, node * & root);
		void display();
		void display(node * root);
		void edit();
		
	private:
		node * root;
};


class smart_pointer
{

	public:
	private:
		//std::unique_ptr<int> valuePtr(new int(15));
};



