using namespace std;
#include<iostream>
#include<vector>
//#include "DLL.h"

//this tpp file includes the implementation of the DLL and 
//node templates
template <typename T> Node<T>::Node ()
{
	terrain = " ";
	next = nullptr;
	previous = nullptr;	

}

//destructor: setting ptrs to null
template <typename T> 
Node<T>::~Node()
{
	next = nullptr;
	previous = nullptr;

}

//copy constructor 
template <typename T> 
Node<T>::Node(const Node<T> & source)
{
	source.terrain = terrain;
	source.next = next;
	source.previous = previous;
}


template <typename T> 
typename Node<T>::node_ptr_type & Node<T>::get_previous() 
{
	return previous;
}

template <typename T> 
typename Node<T>::node_ptr_type & Node<T>::get_next()
{
	return next;
}

template <typename T> 
T Node<T>::get_data() const 
{
	Node & object;
	object.terrain = terrain;
	object.next = next;
	object.previous = previous;
	return object;
}

template <typename T> 
void Node<T>::display() const 
{
	cout << "Terrain: " << terrain << endl;
	return;
}

template <typename T>
void Node<T>::set_previous(Node<T> * set)
{
	previous = set;
}

template <typename T>
void Node<T>::set_next(Node<T> * set)
{
	next = set;
}

template <typename T>
void Node<T>::set_terrain(string add)
{
	terrain = add;
}

template <typename T>
void Node<T>::display_terrain()
{
	cout << terrain << " ";
}

template <typename T>
DLL<T>::DLL( int i)
{
	head = nullptr;

	//creating a vectortor with terrains for each type of race
	//insert node function will take the vectortor and change the 
	//terrain of each node according to the ones set here
	vector<string> track;
	if( i == 1) //street track for buggy
	{
		track.push_back("clear");
		track.push_back("bumpy");
		track.push_back("pedestrians");	
		track.push_back("flat");
		track.push_back("pothole");
		insert(track);
	}
	if(i ==2) //off road racing for dirt bike
	{
		track.push_back("clear");
		track.push_back("dusty/unclear vision");
		track.push_back("bumpy");	
		track.push_back("muddy");
		track.push_back("flat");
		insert(track);
	}
	if(i == 3) //standard track for super cars
	{
		track.push_back("straight");
		track.push_back("bend");
		track.push_back("straight");
		track.push_back("bump");
		track.push_back("flat");
		insert(track);	
	}	
		

}

template <typename T>
DLL<T>::~DLL()
{}

/*
template <typename T>
Node<T>::Node_type & <Node
{}


template <typename T>
typedef Node_type * Node_ptr
{}

template <typename T>
DLL(const DLL<T> & source)
{}*/


template <typename T>
void DLL<T>::insert(vector<string> track)
{

	int size = track.size();
	insert(track, size);
	Node<T> * current = head;
	while(current->get_next())
		current = current->get_next();
	if(!current->get_next())
		tail = current;


}

//using the vector of terrains when created the DLL 
template <typename T>
void DLL<T>::insert( vector<string> track, int & size)
{
	//going backwards in vector
	if(size != 0)
	{	
		Node<T> * temp = head;
		head = new Node<T>;
		head->set_previous(nullptr); 
		head->set_terrain(track[size-1]);
		head->set_next(temp);
		if(temp) //only needed for adding the first node, rest of the time it won't be null
			temp->set_previous(head); 
		insert(track, --size);		
	}
	return;


}
template <typename T>
void DLL<T>:: display() const
{
	if(!head)
		return;
	Node<T> * current = head;
	while(current->get_next())
	{
		current->display_terrain();
		current = current -> get_next();
	}

}


template <typename T>
DLL<T>& DLL<T>::operator =(const DLL<T> & source)
{}

