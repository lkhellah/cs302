#include"clist.h"

int list::count_first()
{
    if(!rear)
        return 0;
    if(rear->next == rear)
        return 1;
    int value = rear->next->data;
    node * current = rear;
    return count_first(rear->next,value, current);
}

int list::count_first(node*&rear, int & value, node * & current)
{
    if(rear == current) 
    {
        if(rear->data == value)
            return 1;
        return 0;
    }
   if(rear-> data == value)
       return count_first(rear->next, value,current) + 1;
   else
    return count_first(rear->next, value, current);


}

//making a copy and returning average
int list::copy(list & copy_into)
{
    if(!rear)
        return 0;
    copy_into.rear  = new node;
    node * current = rear;
    node * new_current = copy_into.rear;
    int count= copy(rear->next, copy_into.rear, current, new_current);
    current = rear->next;
    int sum = rear->data;
    while(current != rear)
    {
        sum += current->data;
        current = current->next;
    }
    int average = sum / count;
    return average; 

}

int list::copy(node * & old_rear, node * & new_rear, node * & current, node * & new_current)
{
    int count {0};
    if(old_rear == current)
    {
        if(old_rear-> data == 2)
            return 0;
        else
        {
            new_rear -> data = old_rear-> data;
            new_rear -> next = new_current;
            return 1;
        }
    }
    if(old_rear->data != 2)
    {
        new_rear->data = old_rear->data;
        new_rear->next = new node;
        new_rear = new_rear->next;
        count = count + 1;
    }

    return count += copy(old_rear->next, new_rear, current, new_current);

}


int list::count_last()
{
    if(!rear)
        return 0;
    int value = rear->data;
    node* current = rear;
    int count = count_last(rear->next, current, value);
    return count;
}

int list::count_last(node * & rear, node * & current, int & value)
{
    if(rear == current)
        return 0;
    if(rear->data == value)
        return count_last(rear->next, current, value) + 1; 
    return count_last(rear->next, current, value);
}

//count values greater than 4
int list::count_four()
{
    if(!rear)
        return 0;
    node * current = rear;
    int count = count_four(rear->next, current);
    return count;
}

int list::count_four(node * & rear, node * & current)
{
    if(rear==current)
    {
        if(rear->data > 4)
            return 1;
        return 0;
    }
    if(rear->data > 4)
        return count_four(rear->next, current) + 1;
    return count_four(rear->next, current);
}



//display all the unique items and return sum of them
int list::display_unique()
{
    if(!rear)
        return 0;
    node * current = rear;
    int array[30];
    int * ptr = array;
    int index {0};
    int sum = display_unique(rear->next, current, ptr, index);
    return sum;
}

int list::display_unique(node * & rear, node * & current, int * & ptr, int & index)
{
    int sum{0};
    int flag{0};
    if(rear == current)
    {
        for(int i = 0; i < 30; ++i)
        {
            if(ptr[i] == rear->data)
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            cout << rear->data << " ";
            return sum += rear->data;
        }
        return 0;
    }

    //ptr[index] = rear->data;
    //++index;
    for(int i = 0; i < 30; ++i)
    {
        if(ptr[i] == rear->data)
            return sum += display_unique(rear->next, current,ptr, index);
    }
    //    else
     //   {
            ptr[index] = rear->data;
            ++index;
            cout << rear->data << " ";
            sum = rear->data;
            return sum += display_unique(rear->next, current, ptr, index);
      //  }
    //}
}


//move first to end, return num of items in list
int list::remove_first()
{
    if(!rear)
        return 0;
    int value = rear->next->data;
    node * hold = rear->next->next;
//    rear->next->next = nullptr;
    delete rear->next;
    rear->next = hold;
 //   hold = nullptr;
    node * current = rear;
    int counting  = remove_first(rear->next, current, value);
    rear = rear->next;
    return counting + 1;
}

int list::remove_first(node*&rear, node * & current, int value)
{
    if(rear == current)
    {
        node * hold = rear->next;
        rear->next = new node;
        rear->next->data = value;
        rear->next->next = hold;
        return 1;
    }
    return remove_first(rear->next, current, value) + 1;
}

//Remove the last ‘2’ and return the total number of 2’s in the list. Do this is only a single traversal.
int list::remove_two()
{
    if(!rear)
        return 0;
    if(rear == rear->next)
    {
        if(rear->data == 2)
        {
            delete rear;
            rear = nullptr;
            return 1;
        }
    }
    node * current = rear;
    int two {0};
    int flag {0};
    remove_two(rear->next, current, two, flag);
    return two;
}

void list::remove_two(node * & rear, node* & current, int & two, int & flag)
{
    if(rear == current)
    {
        if(rear->data == 2)
        {
            node * hold = rear->next;
            delete rear;
            rear = hold;
            ++two;
            flag = 1;
            return;
        }
        return;
    }
    if(rear->data == 2)
        ++two;
    remove_two(rear->next, current, two, flag);
    if(!flag)
    {
        if(rear->data == 2)
        {
            node * hold = rear->next;
            delete rear;
            rear = hold;
            flag = 2;
            return;
        }
    }
    else if (flag == 1)
    {
        this->rear = rear;
        flag = 2;


    }
    return;

}


//Remove all nodes after the last ‘2’ and return the number of nodes removed. Do this in a single traversal. 
int list::remove_special()
{
    if(!rear)
        return 0;
    if(rear->data == 2)
        return 0;
    int flag{0};
    node * current = rear->next; //current is end now
    node * temp = nullptr;
    while(current != rear)
    {
        if(current->data == 2)
            temp = current;
        current = current->next;
    }
    if(!temp)
    {
        cout << "No 2's in list" << endl;
        return 0;
    }
    current = rear;  //current is rear now (redundant since it is set to rear in while loop)
    //temp is the new set to the last 2 which should be the new rear
    int value = remove_special(rear->next, current, temp->next, flag, temp);
}

//temp is the last two(end(
int list::remove_special(node * & rear, node * & current, node * & temp, int & flag, node * end)
{
    int count {0};
    if(rear == current)
    {
        node * hold = rear->next;
        delete rear;
        ++count;
        rear = hold;
        this->rear = end;
        return 0;
    }
    if(rear == temp) //if rear is pointing to the last 2
    {

        node * hold = rear->next;
        delete rear;
        ++count;
        rear = hold; 
        temp = hold;
        flag = 1;
        count += remove_special(rear, current, temp, flag, end);

    } 
    else if(!flag)
        count += remove_special(rear->next, current, temp, flag, end);
    
    return count;
}


//Remove every ‘2’  except the first one. Return the number of 2’s removed. Do this in a single traversal. 
int list::except_first()
{
    if(!rear)
        return 0;
    if(rear == rear -> next)
    {
        if(rear->data == 2)
            return 0;
    }
    node * current = rear->next;
    node * temp = nullptr;
    int found {0};
    while(current!=rear && !found)
    {
        if(current->data == 2)
        {
            temp = current;
            found = 1;
        }
        current = current->next;
    }
    if(current == rear && !found)
    {
        if(current->data == 2)
            temp = current;
    }
    if(!temp)
    {
        cout << "no 2's in the list" << endl;
        return 0;
    }
    node * end = rear;
    int flag = 0;
    int num = except_first(rear->next, end, temp, flag);
    return num;
}

//current means end (rear)
//temp is the 2 i don't delete
int list::except_first(node * & rear, node * & current, node * temp, int & flag)
{
    int count {0};
    if(rear == current)
    {
        if(rear->data == 2 && rear != temp)
        {
            node * hold = rear->next;
            delete rear;
            rear = hold;
            //this->rear = rear;
            flag = 1;
            return 1;
        }
        return 0;
    }
    if (rear->data == 2 && rear!= temp)
    {
        node * hold = rear->next;
        delete rear;
        rear = hold;
        ++count;
        count += except_first(rear, current, temp, flag);
    }
    else
        count += except_first(rear->next, current, temp, flag);
    
    if(flag == 1)
    {
        this->rear = rear;
        flag = 2;
        return count;
    }
    return count;
}


//how to do mpdemo retake 
//make a copy except duplicates
void list::copy()
{
    if(!rear)
        return;
    copy(rear->next, rear);
    return;
}

void list::copy(node * rear, node * end)
{
    if(rear == end)
    {
        int value = 1;
        value = copy(rear->data, rear, rear->next);
        if(value)
        {
            cout << " " << rear->data <<  endl;
        }
        return;
    }
    int value = 1;
    value = copy(rear->data, rear, rear->next);
        int average(node * & root, node * & end, int & count);
    if(value)
        cout << rear->data << " ";
    copy(rear->next, end);
    return;
}

int list::copy(int num, node * check, node * rear)
{
    if (rear == check)
        return 1;
    if(rear->data == num)
        return 0;
    return copy(num, check, rear->next);
}



//(i) Remove the last two nodes, but only if the last node is not a ‘2’. Return the sum of these nodes. 
int list::remove_if()
{
    if(!rear)
        return 0;
    if(rear == rear->next)
        return 0;
    if(rear->data == 2)
    {
        cout << "last node is a 2. so not removing last two nodes." << endl;
        return 0;
    }
    node * end = rear;
    int flag{0};
    int sum = remove_if(end, rear->next, flag);
    return sum;
}


int list::remove_if(node * & end, node * & rear, int & flag)
{
    int sum{0};
    if(rear->next == end)
    {
        node * hold = rear->next;
        sum += rear->data;
        delete rear;
        rear = hold;
        hold = rear->next;
        sum += rear->data;
        delete rear;
        rear = hold;
        flag = 1;
        return sum;
    }
    sum = remove_if(end, rear->next, flag);
    if(flag == 1)
    {
        this->rear = rear;
        flag =2;
        return sum;
    }
    return sum;
}

//Make a copy of the data structure, but only copy even data. Return the number 
//of nodes copied. Do not implement this with an insert function! Traverse only once
int list::copy_even(list & obj)
{
    if(!rear)
        return 0;
    node * end = rear;
    obj.rear = new node;
    node * new_front = obj.rear;
    int num = copy_even(rear->next, end, new_front, obj.rear);
    return num;
}

int list::copy_even(node * & rear, node * & end, node * & new_front, node * & new_rear)
{
    int count {0};
    if(rear == end)
    {
        if(rear->data % 2 == 0)
        {
            new_rear->data = rear->data;
            new_rear->next = new_front;
            return count += 1;
        }
        new_rear->next = new_front;
    }
   if(rear->data % 2 == 0)
    {
        new_rear->data = rear->data;
        new_rear->next = new node;
        new_rear = new_rear->next;
        return copy_even(rear->next, end, new_front, new_rear) + 1;
    }

    return copy_even(rear->next, end, new_front, new_rear);

}

//Create an average of all of the even data in the data structure 
int list::average()
{
    if(!rear)
        return 0;
    node * end = rear;
    int count {0};
    int sum = average(rear->next, end, count);
    cout << "sum of even values: " << sum << endl;
    cout << "count of even values: " << count << endl;
    return sum/count;
    
}

int list::average(node * & rear, node * & end, int & count)
{

    int sum{0};
    if(rear == end)
    {
        if(rear->data % 2 == 0)
        {
            ++count;
            return rear->data;
        }
    }
    if(rear->data % 2 == 0)
    {
        sum += rear->data;
        ++count;
    }
    return sum += average(rear->next, end, count);
}

            
//Sum all of the data less than 10 in the data structure 
int list::sum_special()
{
    if(!rear)
        return 0;
    node * end = rear;
    int sum = sum_special(rear->next, end);
}

int list::sum_special(node * & rear, node * & end)
{
    int sum{0};
    if(rear == end)
    {
        if(rear->data < 10);
            return rear->data;
        return 0;
    }
    if(rear->data < 10)
        sum += rear->data;
    return sum+= sum_special(rear->next, end);
}


//(n) make a copy of unique data

