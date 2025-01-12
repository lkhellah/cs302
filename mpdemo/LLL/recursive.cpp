#include"list.h"
bool list::add_unique(int new_data)
{
    if(!head)
    {
        head = tail = new node;
        head->data = new_data; 
        head->next = nullptr;
        return true;
    }
    return add_unique(head, new_data);
}

bool list::add_unique(node * & head, int new_data)
{
    if(!head)
    {
        head = tail = new node;
        head->data = new_data;
        head->next = nullptr;
        return true;
    }
    if(head->data == new_data)
        return false;
    return add_unique(head->next, new_data);
}


int list::count_first()
{
    if(!head)
        return 0;
    int send = head->data;
    return count_first(head, send) - 1;
}


int list::count_first(node * & head, int value)
{
    if(!head)
        return 0;
    if(head->data == value)
        return count_first(head->next, value) + 1;
    return count_first(head->next, value);
}


int list::remove_first()
{
    if(!head)
        return 0;
    if(head==head->next)
        return 0;
    int value = head->data;
    node * temp = head->next;
    delete head;
    head = temp;
    return remove_first(head, value);
}

int list::remove_first(node * & head, int & value)
{
    if(!head->next)
    {
        head->next = new node;
        head->data = value;
        head->next = nullptr;
        return 1;
    }
    return remove_first(head->next, value) + 1;

}
