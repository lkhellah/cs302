#include "list.h"



int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
        
   //int value = object.count_first();
   //cout << "number of values same as first: " << value << endl;
   
    int value = object.remove_first();
    cout <<"remove first function, numver of items is: " << value << endl;
    

    object.display();  //displays the LLL again!
   
    
    return 0;
}
