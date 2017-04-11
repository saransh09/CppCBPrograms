#ifndef stackLL_h
#define stackLL_h
#include<iostream>
using namespace std;

template<typename T>

struct Node
{
    T data;
    T * next;
};

class Stack_LL()
{
    int size;
    Node * head;

public:

    Stack_LL() : size(0),ptr(0)
    {

    }

    Stack_LL(T x)
    {
        if(head==NULL)
        {
            Node * ptr = new Node;
            ptr ->data=x;
            ptr ->next = NULL;
            head = ptr;
            size = 1;
        }
        else
        {
            Node * temp = head;
            while(temp!=NULL)
            {
                temp = temp->next;
            }
            Node * ptr = new Node;
            ptr -> data = x;
            ptr -> next = NULL;
            temp->next = ptr;
        }
    }

    void clear()
    {
        Node * temp = head;
        while(head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    ~Stack_LL()
    {
        clear();
    }

    Stack_LL(const Stack_LL()<T> & b) : size(b.size)
    {
        clear();
        Node * p = b.head;
        while(p)
        {
            Stack_LL(T b.p->data);
            p = p->next;
        }
    }
};


#endif // stackLL_h
