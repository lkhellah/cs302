//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
   public:
   		//These functions are already written
   		list();			//supplied
   		~list();		//supplied
   		void build();	//supplied
   		void display();	//supplied
        void remove_last();
        void remove_first_last();
        void remove_every_other();
        int copy(list & copy_into);
        int count_last();
        int count_four();
        int display_unique();
        int remove_first();
        int remove_two();
        int remove_special();
        int except_first();
        void copy();
        int remove_if();
        int copy_even(list & obj);
        int average();
        int sum_special();
	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
    //recursive:
    int count_first();

	private:
		node * rear;
        void remove_last(node * & rear);
        void remove_first_last(node * & rear);
        void remove_every_other(node * & rear);
        

    //recursive
        int count_first(node * & rear, int& value, node * & current);
        int copy(node * & rear, node * & new_rear, node * & current, node * & new_current);
        int count_last(node * & rear, node * & current, int & value);
        int count_four(node * & rear, node * & current);
        int display_unique(node * & rear, node * & current, int * & ptr , int & index);
        int remove_first(node * & rear, node * & current, int value);
        void remove_two(node * & rear, node * & current, int & two, int & flag);
        int remove_special(node * & rear, node * & current, node * & temp, int & flag, node * end);
        int except_first(node * & rear, node * & current, node * temp, int & flag);
        void copy(node * rear, node * end);
        int copy(int num, node * check, node * rear);
        int remove_if(node * & rear, node * & end, int & flag);
        int copy_even(node * & rear, node * & end, node * & new_front, node * & new_rear);
        int average(node * & root, node * & end, int & count);
        int sum_special(node * & root, node * & end);


};
