#include"vehicles.h"
#include<array>
#include<vector>
#include<string>

//based on LAB 4 .h

template <typename T>
class Node
{

	public:
		Node<T> ();
		~Node();
		typedef Node<T> * node_ptr_type; //didn't implement yet
		Node(const Node<T> & source); 
		node_ptr_type & get_previous();
		Node<T> * & get_next();
		void set_previous(Node<T> *);
		void set_next(Node<T> *);
		void set_terrain(string add);
		T get_data() const;
		void display() const;
		void display_terrain();
			

	protected:
		T array[3];
		string terrain;
		node_ptr_type next;
		node_ptr_type previous;
};


template <typename T>
class DLL
{

	public:
		DLL<T> (int);
		~DLL();
		typedef Node<T>  node_type;
		typedef node_type * node_ptr;
		DLL(const DLL<T> & source);
		void insert(vector <string> track);
		void display() const;
		DLL<T> & operator=(const DLL<T> & source);	
		void start_race(const T & car_one, const T & car_two);	
		
 
	private:
		 node_ptr head;
		 node_ptr tail;
		 void copy(node_ptr & dest, const node_ptr & source);
		 void insert(vector <string> track, int & size); 
		 void display(const node_ptr & root) const;

};

#include "DLL.tpp"
