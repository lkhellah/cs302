#include"list.h"

bool  list::remove_first_last()
{
    if(!head)
        return false;
    return remove_first_last(head);
}

bool list::remove_first_last(node * & head)
{
    if(head == tail)
    {
        delete head;
        head = tail = nullptr;
        return true;
    }
    else
    {
        //deleting first
        node * temp = head->next;
        delete head;
        head = temp;
      
        //deleting last
        node * previous = temp;
        if(temp->next)
        {
             while(temp->next)
            {
                previous = temp;
                temp = temp->next;
            }
        }

        if(head == temp)
        {
            delete head;
            temp = head = tail = nullptr;
            return true;
        }
        else
        {
            delete temp;
            temp = nullptr;
            tail = previous;
            tail-> next = nullptr;
            return true;
        }

    }
    


}



void list::remove_every_other()
{
    if(!head)
        return;
    return remove_every_other(head);
}

void list::remove_every_other(node * & head)
{
    if(!head)
        return;
    node * temp = head;
    node * current = head;
    node * hold = nullptr;
    if(current->next)
    {
        while(current->next)
        {
            if(current->next == tail)
            {
                delete tail;
                head -> next =nullptr;
                tail = head;
                return;
            }
            temp = current->next;
            current->next = temp -> next;
            //temp->next = nullptr;
            delete temp;
            temp = nullptr;
            hold = current;
            current = current -> next;

        }
    }
    if(current == tail)
    {
        delete current;
        hold -> next = nullptr;
        tail = hold;
        return;
    }
    return;
}




void list::add_end()
{
    if(!head)
    {
        head = new node;
        head->data = 99;
        head->next = nullptr;
        tail = head;
    }
    return add_end(head, 99);
}


void list::add_end(node * & head, int value)
{

    node * current = head;
    while(current-> next)
        current = current -> next;
    if(!current->next)
    {
        current -> next = new node;
        current = current -> next;
        current -> data = value;
        current -> next = nullptr;
        tail = current;
        return;
    }

}


void list::copy()
{
    if(!head)
        return;
    node * obj;
    return copy(head, obj);
}

void list::copy(node * & head, node * & obj)
{
    node *current = head;    
    if(current)
    {
        obj = new node;
        node * hold = obj;
        
        while(current)
        {
            hold -> data = current-> data;
            current = current -> next;
            if(current)
                obj-> next = new node;
        }
        if(!current)
            obj->next = nullptr;

    }
    cout << "displaying copy from func: \n";
    node * temp = obj;
    while(temp)
    {
        cout << temp -> data;
        temp = temp -> next;
    }
}







