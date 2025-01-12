//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;   //some questions are a char * data;
    node * next;
};

class list
{
   public:
   //These functions are already written for you
     list();			//supplied
     ~list();			//supplied
     void build();     		//supplied
     void display();  		//supplied 
    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
     bool remove_first_last();
     void remove_every_other();
     void add_end();
     void copy();

     //recursive:
     bool add_unique(int new_data);
     int count_first();
     int remove_first();
   private:		//notice there is both a head and a tail!
      node * head;
      node * tail;
      bool remove_first_last(node * & head);
      void remove_every_other(node * & head);
      void add_end(node * & head, int value);
      void copy(node * & head, node * & obj);

    //recursive
      bool add_unique(node * & head, int new_data);
      int count_first(node * & head, int value);
      int remove_first(node * & head, int & value);
};
