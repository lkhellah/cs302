//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class table
{
    public:
    	//These functions are supplied already
    	table();			//supplied
    	~table();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied
        int count_nodes();
        int count_value();
        int retrieve_second_largest();
        void remove_two();
        int find_largest();
        int find_largest_two();
        int count_special();
        int remove_leaves();
        int remove_largest_special();
        int IOS();
        int largest();
        int remove_special();
        int copy_largest(table & to_add);
        void copy_largest_two(table & to_add);
        void display_special();
        void sum_special();
        int sum_path();

/* ************** PLACE YOUR PUBLIC PROTOTYPE HERE ***************** */
 
 
 	private:
 		node * root;

/* ************** PLACE YOUR PRIVATE PROTOTYPE HERE ***************** */
        int count_nodes(node *  root);
        int count_value(node * root, int value);
        void retrieve_second_largest(node * root, int & c, int & value);
        void remove_two(node * & root, int & flag);
        int find_largest(node * root);
        int find_largest_two(node * root);
        int count_special(node * & root);
        int remove_leaves(node * & root);
        int remove_largest_special(node * & root);
        int IOS(node * & root);
        int largest(node * & root);
        int node_IOS(node * & root);
        int remove_special(node * & root, node * & ptr);
        void copy_largest(node * & root, int largest);
        void display_special(node * root, int largest);
        int sum_special(node * root, int & sum, int & count);
        int height(node * root);
        int sum_path(node * root);
};
  

