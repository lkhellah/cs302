#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    
    //count first
    //cout << "num of values same as first: " << object.count_first() << endl;

    //count last
    //cout << "num of values same as last: " << object.count_last() << endl;

    //display unique and return sum of them
    /*int sum = object.display_unique();
    cout << "unique sum is: " << sum << endl;
    object.display();*/

    //remove first, place last, return num of tiems in list
    //int count = object.remove_first();
    //cout << "num of items is: " << count << endl;
    
    //display unique implemented without a for loop
    //int sum = object.display_unique_two();
    //cout << "sum of unique values: " << sum << endl;

    //Remove the last ‘2’ and return the total number of 2’s in the list. Do this is 
    //only a single traversal. 
    //object.remove_last();
    
    //Remove all nodes after the last ‘2’ and return the number of nodes removed. 
    //Do this in a single traversal. 
    //object.remove_after();
    
    //Remove every ‘2’  except the first one. Return the number of 2’s removed. Do this in a single traversal. 
    //object.remove_except();
    
    //Remove the last two nodes, but only if the last node is not a ‘2’. Return the sum of these nodes. 
    //int sum = object.last_two();
    //cout << "sum of last two is: " << sum << endl;

    //Make a copy of the data structure, but only copy even data. Return the number 
    //of nodes copied. Do not implement this with an insert function! Traverse only once. 
    list obj;
    int count = object.copy_even(obj);
    cout << "displaying new even obj: ";
    obj.display();

 
    object.display();
    return 0;
}
