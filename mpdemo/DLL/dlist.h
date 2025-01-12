//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        

        int count_first();
        int count_last();
        int count_four();
        int display_unique();
        int remove_first();
        int display_unique_two();
        int remove_last();
        int remove_after();
        int remove_except();
        int last_two();
        int copy_even(list & obj);
     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
     
     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
                    
         int count_first(node * & head, int & value);
         int count_last(node * & head, int value);
         int count_four(node * & head);
         int display_unique(node * & head, int * & array, int & index);
         int remove_first(node * & head, int value, node * & tail, node * & before);
         int display_unique_two(node * head, node *  tail);
         int display_unique_two(int value, node * & current, node * & head, node * & tail);
        int remove_last(node * & head, node * & tail, node * & two, node * & before);
        void find_two(node * & head, node * & tail, node * & two);
        int remove_after(node * & head, node * & tail, node * & two);
        int remove_after(node * & head,  node * & tail, node * & before, node * & two);
        void find_first_two(node * & head, node * & tail, node * & two);
        int remove_except(node * & head, node * & tail, node * & two, node * & before);
        int last_two(node * & head, node * & tail, node * & before);
        int copy_even(node * & head, node * & tail, node * & new_head, node * & new_tail, int & flag);

};
