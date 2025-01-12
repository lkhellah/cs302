#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    list object_two;


    //average: 
    /*int average = object.copy(object_two);
    cout << "average is: " << average;
    object_two.display();*/

    //count_last
    /*int last = object.count_last();
    cout << "number of last value in list is: " << last << endl;*/

    //count greater than 4
    /*int count = object.count_four();
    cout << "number of values greater than 4 is: " << count << endl;*/

    //display unique and sum them
    //minor error, not sure if its my fault or the .o
    //when display function says: This list contains 11 number of items, 11 
    //is also not displayed even if it is unique (11 is just an ex)
    //int sum= object.display_unique();
    //cout << "sum of unique: " << sum << endl;

    //remove first and plance at end, return num of items in list
    //int count = object.remove_first();
    //cout << "num of items from remove func: " << count << endl;

    //remove last 2, reutrn total num of 2's
    //int two = object.remove_two();
    //cout << "num of twos is: " << two << endl;
    
    //Remove all nodes after the last ‘2’ and return the number of nodes removed. Do this in a single traversal. 
    //int count = object.remove_special();
    //cout << "num of things deleted: " << count << endl;
    
    //Remove every ‘2’  except the first one. Return the number of 2’s removed. Do this in a single traversal. 
    /*int count = object.except_first();
    cout << "num of 2's deleted: " << count << endl;*/


    //mpdemo retake, displaying unique values
    //object.copy();
    

    //Remove the last two nodes, but only if the last node is not a ‘2’. Return the sum of these nodes. 
    //int sum = object.remove_if();
    //cout << "sum of objects removed: " << sum << endl;
    
    //Make a copy of the data structure, but only copy even data. Return the number 
    //of nodes copied. Do not implement this with an insert function! Traverse only once.
    /*list obj;
    int count = object.copy_even(obj);
    cout << "num of objects copied: " << count << endl;
    cout << "new object is: " << endl;
    obj.display();
    cout << endl << endl;*/

    //Create an average of all of the even data in the data structure 
    /*int average = object.average();
    cout << "average is: " << average << endl;*/


    //Sum all of the data less than 10 in the data structure 
    int sum = object.sum_special();
    cout << "sum of data less than 10 is: " << sum << endl;

    object.display(); //resulting list after your function call!
    
    return 0;
}
