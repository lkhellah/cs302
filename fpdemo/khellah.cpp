#include"table.h"


int table::count_nodes()
{
    if(!root)
        return 0;
    return count_nodes(root);
}

int table::count_nodes(node * root)
{
    if(!root)
        return 0;
    int counter = 1;
    counter += count_nodes(root->left);
    counter += count_nodes(root->right);
    return counter;
}



int table::count_value()
{
    return count_value(root, 15);
}

int table::count_value(node * root, int value)
{
    if(!root)
        return 0;
    int count {0};
    if(root->data == value)
        count = 1;
    count += count_value(root->left, value);
    count += count_value(root->right, value);
    return count;
}

//find in order successor
int table::retrieve_second_largest()
{
    if(!root)
        return 0;
    
    int c = 0;
    int value;
    retrieve_second_largest(root, c, value);
    return value;
}

void table::retrieve_second_largest(node * root, int & c, int & value)
{
    if(!root || c > 2)
        return;

    retrieve_second_largest(root->right, c, value);

    c++;

    if(c == 2)
    {
        value = root->data;
        return;
    }


    retrieve_second_largest(root->left, c, value);
}

//remove largest two
void table::remove_two()
{
    if(!root)
        return;
    int flag = 0;
    remove_two(root, flag);
    flag = 0;
    remove_two(root, flag);
    return;
}

void table::remove_two(node * & root, int & flag)
{
    if(!root)
        return;
    
    remove_two(root->right, flag);
    if(root->left && flag == 0)
    {
        node * hold = root->left;
        delete root;
        root = hold;
        flag = 1;
        return;
    }
    if(!flag)
    {
        delete root;
        root = nullptr;
        flag = 1;
        return;
    }
}
/*
//karlas remove largest two:
int table::remove_special()
{
    if(!root)
        return 0;
    if(!root->right)
        //special case, root is largest
         int largest = root->data;
    return remove_special(root);
{
int table::remove_special(node * & root)
{
    //go all the way right
    if(!root->right)
    {
        largest = root->data;
        if(root->left)
            int sec = get_second(root->left);
    }
}
//goes all the way right of left subtree sent in to this function
int table::get_second(node * & root)
{
    if(!root->right)
        int sec = root->data;
}
*/    
int table::find_largest()
{
    return find_largest(root);
}

int table::find_largest_two()
{

    return find_largest_two(root->right);
}
int table::find_largest(node * root)
{
    if(!root)
        return 0;
    int largest{0};
    int left = find_largest(root->left);
    int right = find_largest(root->right);
    largest = max(left,right);
    if(root->data > largest)
        largest = root->data;
    return largest;
}

//version two, only goes right
int table::find_largest_two(node * root) 
{
    if(!root)
        return 0;
    int right = find_largest_two(root->right);
    if(!right) //using the return 0 as a flag, since it will be stored in right
        return root->data;
}
//count number of nodes in largest node's left subtree
int table::count_special()
{
    return count_special(root);
}

int table::count_special(node * & root)
{
    if(!root)
        return 0;
    int largest {0};
    int right = count_special(root->right);
    if(!right)
    {
        largest = root->data;
        cout << "largest is: " << largest << endl;
        if(root->left)
        {
            int count = count_nodes(root->left);
            return count;
        }
    }
    //else
        //return 0;
}

int table::remove_leaves()
{
    if(!root)
        return 0;
    return remove_leaves(root);
}


int table::remove_leaves(node * & root)
{
    if(!root)
        return 0;
    else if(!root->left && !root->right)
    {
        delete root;
        root = nullptr;
        return 1;
    }
    int left = remove_leaves(root->left);
    int right = remove_leaves(root->right);
    return left + right;
}


//remove largest in left subtree
int table::remove_largest_special()
{
    if(!root)
        return 0;
    return remove_largest_special(root->left);
}

int table::remove_largest_special(node * & root)
{
    if(!root)
        return 0;
    int right = remove_largest_special(root->right);
    if(!right)
    {
        if(root->left)
        {
            node * hold = root->left;
            delete root;
            root = hold;
        }
        else
        {
            delete root;
            root = nullptr;
        }
    }
}



//put prototype in .h for it to work
//only for root's IOS
int table::IOS()
{
    if(!root)
        return 0;
    return IOS(root->right);
}

int table::IOS(node * & root)
{
    if(!root)
        return 0;
    int left = IOS(root->left);
    if(!left)
        return root->data;

}

//retrieve second largest another way:
int table::largest()
{
    if(!root)
        return 0;
    return largest(root->right);
}

int table::largest(node * & root)
{
    int second_largest;
    if(!root)
        return 0;
    int traverse = largest(root->right);
    if(traverse ==2) //for return 2 if parent is second largest
    {
        second_largest = root->data;
        return second_largest;
    }
    //largest found
    if(!traverse)
    {
        //largest is root->data;
        cout << "largest from function: " << root->data << endl;
        if(!root->left)
            return 2; //flag since parent is second largest
        else
            second_largest = node_IOS(root->left);
    }
}

int table::node_IOS(node * & root) //rightmost in left subtree
{
    if(!root)
        return 0;
    int right = node_IOS(root->right);
    if(!right)
        return root->data;
}



//add root and root's IOS
//sum all of the data of farthest length of the tree


//remove everything except root
int table::remove_special()
{
    if(!root)
        return 0;
    node * ptr = root;
    return remove_special(root, ptr);
}

int table::remove_special(node * & root, node * & ptr)
{
    if(!root)
        return 0;
    int left = remove_special(root->left, ptr);
    int right = remove_special(root->right, ptr);
    if(root == ptr)
        return 0;
    
    delete root;
    root = nullptr;
    return left+right + 1;
}

//copy largest item and place it in a new BST
int table::copy_largest(table & to_add)
{
    if(!root)
        return 0;
    int largest = find_largest_two(root->right);
    cout << "largest to be added is: " << largest << endl;
    copy_largest(to_add.root, largest);
}

void table::copy_largest(node * & root, int largest)
{
    if(!root)
    {
        root = new node;
        root->data = largest;
        root->left = root->right = nullptr;
        return;
    }
    if(largest < root->data)
    {
        copy_largest(root->left, largest);
    }
    
    else
    {
        copy_largest(root->right, largest);
    }
    return; 
}

void table::copy_largest_two(table & to_add)
{
    if(!root)
        return;
    int largest = find_largest_two(root->right);
    cout << "largest is: " << largest << endl;
    int c{0}; 
    int value; //will have second largest
    retrieve_second_largest(root, c , value);
    cout << "second largest is: " << value << endl;
    copy_largest(to_add.root, largest);
    copy_largest(to_add.root, value);
    return;
}

//Display everything except for the largest item
void table::display_special()
{
    if(!root)
        return;
    int largest = find_largest_two(root->right);
    display_special(root, largest);
}

void table::display_special(node * root, int largest)
{
    if(!root)
        return;
    display_special(root->left, largest);
    if(root->data != largest)
        cout << root->data << " ";
    display_special(root->right, largest);
}

//avg all data along paht from root to largest
void table::sum_special()
{
    if(!root)
        return;
    int sum{0};
    int count{0};
    sum_special(root, sum, count);
    cout << "sum: " << sum << endl;
    cout << "count: " << count << endl;
    cout << "average: " << sum/count << endl;
}
int table::sum_special(node * root, int & sum, int & count)
{
    if (!root)
        return 0;
    sum += root->data;
    ++count;
    int right = sum_special(root->right, sum, count);
    if(!right) //largest is here
        return 0;
}

//sum longest path of the tree
int table::sum_path()
{
    if(!root)
        return 0;
    return sum_path(root);

}
int table::sum_path(node * root)
{
    if(!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + root->data;
}
int table::height(node * root)
{
    if(!root)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    int the_height = max(left_height, right_height);
    return the_height + 1;
}

