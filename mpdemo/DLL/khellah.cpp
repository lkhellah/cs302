#include"dlist.h"

int list::count_first()
{
    if(!head)
        return 0;
    if(head == tail)
        return 1;
    int value = head->data;
    return count_first(head, value);
}

int list::count_first(node * & head, int & value)
{
    if(head == tail)
    {
        if(head->data == value)
            return 1;
        return 0;
    }
    if(head->data == value)
        return count_first(head->next, value) + 1;
    return count_first(head->next, value);
}


int list::count_last()
{
    if(!head)
        return 0;
    if(head == tail)
        return 1;
    int value = tail->data;
    return count_last(head, value);
}
int list::count_last(node * & head, int value)
{
    if(head == tail)
    {
        if(head->data == value)
            return 1;
        return 0;
    }
    if(head->data == value)
        return count_last(head->next, value) + 1;
    return count_last(head->next, value);
}

int list::count_four()
{
    if(!head)
        return 0;
    if(head==tail)
    {
        if(head->data > 4)
            return 1;
        return 0;
    }
    return count_four(head);
}

int list::count_four(node * & head)
{
    if(head == tail)
    {
        if(head->data > 4)
            return 1;
        return 0;
    }
    if(head->data > 4)
        return count_four(head->next) + 1;
    return count_four(head->next);
}


int list::display_unique()
{
    if(!head)
        return 0;
    if(head==tail)
    {
        cout << head->data << endl;
        return head->data;
    }
    int num[20];
    int index{0};
    int * a = num;
    return display_unique(head, a, index);
}

int list::display_unique(node * & head, int * & a, int & index)
{
    int sum{0};
    if(head == tail)
    {
        for(int i = 0; i < 20; ++i)
        {
            if(a[i] == head->data)
                return 0;
        }
        a[index] = head->data;
        cout << head->data << " ";
        return sum += head->data;
    }
    for(int i = 0; i < 20; ++i)
    {
        if(head->data == a[i])
            return sum+= display_unique(head->next, a, index);
    }
    a[index] = head->data;
    ++index;
    cout << head->data << " ";
    sum += head->data;
    return sum+= display_unique(head->next, a, index);
}

//first display unique is bad, makes an array of arbitrary size and use a loop

int list::display_unique_two()
{
    if(!head)
        return 0;
    int sum = display_unique_two(head, tail);
    return sum;
}

int list::display_unique_two(node * head, node * tail)
{
    int sum{0};
    int flag {0};
    if(head == tail)
    {
        flag = display_unique_two(head->data, head, this->head, tail);
        if(!flag)
        {
            cout << head->data << " ";
            return head->data;
        }
        return 0;
    }
    
    flag = display_unique_two(head->data, head, this->head, tail);
    if(!flag)
    {
        cout << head->data << " ";
        sum += head->data;
    }
    return sum += display_unique_two(head->next, tail);

}

int list::display_unique_two(int value, node * & current, node * & head, node * & tail)
{
    if(head == tail && head == current)
        return 0;
    if(head == tail)
    {
        if(head->data == value)
            return 1;
        return 0;
    }
    if(head->data == value && head!=current)
        return 1;
    return display_unique_two(value, current, head->next, tail);
}
        
//Remove the first node and place it at the end of the list; return the number of items in the list. 
int list::remove_first()
{

    if(!head)
        return 0;
    if(head == tail)
        return 1;
    int value = head->data;
    node * hold = head->next;
    delete head;
    head = hold;
    head->previous = nullptr;
    cout << "first value: " << value << endl;
    node * before = head;
    int count = remove_first(head,value, tail,before) + 1;
    return count + 1;

}

int list::remove_first(node * & head, int value, node * & tail, node * & before)
{
    if(head->next == nullptr)
    {
        head->next = new node;
        head->next->previous = before->next;
        head->next->data = value;
        tail = head->next;
        tail->next = nullptr;
        return 0;
    }
    before = head;
    return remove_first(head->next, value, tail, before)+ 1;
}

//(f) Remove the last ‘2’ and return the total number of 2’s in the list. Do this is only a single traversal. 
int list::remove_last()
{
    //cout << tail->data;
    if(!head)
        return 0;
    if(head == tail)
    {
        if(head->data == 2)
        {
            delete head;
            head = tail = nullptr;
            return 1;
        }
        return 0;
    }
    node * two = nullptr;
    find_two(head, tail, two); //two is now pointing to the last two
    if(!two)
    {
        cout << "no twos in the list.\n\n";
        return 0;
    }
    else
    {
        node * before = head;
        int num = remove_last(head, tail, two, before);
        return num;
    }
}

int list::remove_last(node * & head, node * & tail, node * & two, node * & before)
{
    int count{0};
    if(head == two && head == tail)
    {
        delete head;
        head = nullptr;
        tail = before->next;
        //head->previous = before;
        return 1;
    }
    if(head == tail && head != two)
        return 0;
    if(head == two)
    {
        node * hold = head->next;
        delete head;
        head = hold;
        hold->previous = before->next;
        return 1;
    }
    if(head->data == 2 && head!= two)
        ++count;
    return count += remove_last(head->next, tail, two, before);
}
        
void list::find_two(node * & head, node * & tail, node * & two)
{
    if(head == tail)
    {
        if(head->data == 2)
        {
            two = head;
            return;
        }
        return;
    }
    if(head->data == 2)
        two = head;
    return find_two(head->next, tail, two);
}


//Remove all nodes after the last ‘2’ and return the number of nodes removed. Do this in a single traversal. 
int list::remove_after()
{
    if(!head)
        return 0;
    if(tail->data == 2)
        return 0;
    node * two = nullptr;
    find_two(head, tail, two);
    if(!two)
    {
        cout << "no twos in the list.\n\n";
        return 0;
    }
    else
    {
        node * before = head;
        int num = remove_after(head, tail, before, two);
        return num;
    }
}

int list::remove_after(node * & head,  node * & tail, node * & before, node * & two) //two will be the new tail
{

    if(head == two)
    {
        return remove_after(head->next, tail, two);
    }
    return remove_after(head->next, tail, before, two);
}

int list::remove_after(node * & head, node * & tail, node * & two)
{

    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = two;
        return 1;
    }

    node * hold = head->next;
    delete head;
    head = hold;
    return remove_after(head, tail, two) + 1;
}


//Remove every ‘2’  except the first one. Return the number of 2’s removed. Do this in a single traversal. 
int list::remove_except()
{
    if(!head)
        return 0;
    if(head == tail)
        return 0;
    node * two = nullptr;
    find_first_two(head, tail, two);
    if(!two)
    {
        cout << "no 2's in the list.\n\n";
        return 0;
    }
    else
    {
        node * before = head;
        int count = remove_except(head, tail, two, before);
        return count;
    }
}

int list::remove_except(node * & head, node * & tail, node * & two, node * & before)
{
    int count {0};
    if(head == tail)
    {
        if(head->data == 2 && head!=two)
        {
            delete head;
            head = nullptr;
            tail = before->next;
            return 1;
        }
        return 0;
    }
    if(head->data == 2 && head!= two)
    {
        node * hold = head->next;
        delete head;
        head = hold;
        hold->previous = before->next;
    }
    return count += remove_except(head->next, tail, two, before);
}
void list::find_first_two(node * & head, node * & tail, node * & two)
{
    if(head->data == 2)
    {
        two = head;
        return;
    }
    if(head == tail)
        return;
    return find_first_two(head->next, tail, two);
}

//Remove the last two nodes, but only if the last node is not a ‘2’. Return the sum of these nodes. 
int list::last_two()    
{
    if(!head)
        return 0;
    if(tail -> data == 2)
        return 0;
    node * before = head;
    int sum = last_two(head, tail, before);
}

int list::last_two(node * & head, node * & tail, node * & before)
{
    int flag{0};
    int sum{0};
    if(head == tail)
    {
        sum += head->data;
        delete head;
        head = nullptr;
        sum += before->data;
        before->previous->next = nullptr;
        delete before;
        before = nullptr;
        //tail = before;
        flag = 1;
        return sum;
    }
    
    before = head;
    sum += last_two(head->next, tail, before);
    if(flag == 1)
    {
        this->tail = head;
        flag = 2;
        return sum;
    }
}


//Make a copy of the data structure, but only copy even data. Return the number 
//of nodes copied. Do not implement this with an insert function! Traverse only once. 
int list::copy_even(list & obj)
{
    if(!head)
        return 0;
    int flag {0};
    int count = copy_even(head, tail, obj.head, obj.tail, flag);
    obj.head->previous = nullptr;
    return count;
}

int list::copy_even(node * & head, node * & tail, node * & new_head, node * & new_tail, int & flag)
{
    int count{0};
    if(head == tail)
    {
        if(head->data % 2 == 0)
        {
            new_head = new node;
            new_head->data = head->data;
            ++count;
            flag = 1;
            return count;
        }
        flag = 1;
        return 0;
    }
    
    if(head->data % 2 == 0)
    { 
        new_head = new node;
        new_head->data = head->data;
        ++count; 
        count += copy_even(head->next, tail, new_head->next, new_tail, flag);
    }
    else
        count += copy_even(head->next, tail, new_head, new_tail, flag);
    if(new_head->next)
        new_head->next->previous = new_head;
    if(flag == 1)
    {
        new_tail = new_head;
        flag = 2;
        return count;
    }
}






