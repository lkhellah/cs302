#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST
    
    table object_two;
    object_two.build();
   // cout << "SECOND OBJECT:\n";
    //object_two.display();
    /*  PLACE YOUR FUNCTION CALL HERE */
    
    //int count = object.count_nodes();
    //cout << "count is: " << count << endl;

    //int count = object.count_value();
    //cout << "15 count: " << count << endl;

    //int second_largest = object.retrieve_second_largest();
    //cout << "second largest: " << second_largest << endl;

    //int second_large = object.largest();
    //cout << "other second largest: " << second_large << endl;

    //int in_order_successor = object.IOS();
    //cout << "IOS: " << in_order_successor << endl;


    //object.remove_two();
    //int largest = object.find_largest();
    //cout << "largest is: " << largest << endl;

    //int other_largest = object.find_largest_two();
    //cout << "modified largest is: " << other_largest << endl;

    //int count = object.count_special();
    //cout << "number of nodes in largest's left subtree: " << count << endl;

    //int count = object.remove_leaves();

    //height: post order, work done after recursive call
    //duplicates: in order

    //int count = object.remove_largest_special();
    

    //remove all besides root
    //object.remove_special();


    //object.copy_largest_two(object_two);
    //cout << "NEW OBJECT: " << endl;
    //object_two.display();

    //object.display_special();


    //object.sum_special();


    int sum = object.sum_path();
    cout << "sum of longest path: " << sum << endl;

    object.display();	//displays again after!

    return 0;
}
