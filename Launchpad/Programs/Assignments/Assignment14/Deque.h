#ifndef deque_h
#define deque_h
#include<iostream>
using namespace std;

template<typename T>

struct Node
{
    T data;
    Node * next;
};

class Deque()
{
    Node * f;
    Node * r;
    int s;

    void cl()
    {
        while(f)
        {
            Node * t = f;
            f = f->next;
            delete t;
        }
        s=0;
    }
public:

    Deque() : f(0),r(0),l(0){}

    int size()
    {
        return s;
    }

    void clear()
    {
        cl();
    }

    ~Deque()
    {
        cl();
    }

    void InsertAtRear()
    {

    }

    Deque(const Deque & D) : s(D.s)
    {
        Node * temp = new Node;
        while()

    }

};

#endif // deque_h
