#ifndef DynamicQueue_H
#define DynamicQueue_H
#include<iostream>
using namespace std;

template <typename T>
class myQueue
{
    T * ptr;   //For the heap
    int f,r;
    unsigned int s,c;    //Size,Allocation Made

public:
    myQueue():ptr(0),f(-1),r(0),s(0),c(0){}

    bool isEmpty() const
    {
        return s==0;
    }

    int size()
    {
        return s;
    }

    void clear()
    {
        if(ptr)
        {
            delete ptr;
            ptr = 0;
            s = c = 0;
            f = -1;
            r = 0;
        }
    }

    ~myQueue()
    {
        clear();
    }

    myQueue(const myQueue & Q) : c(Q.c), s(Q.s), f(Q.s), r(Q.s)
    {
        ptr = new T[c];
        for(int i=0;i<c;i++)
        {
            ptr[i] = Q.ptr[i];
        }
    }

    myQueue & operator=(const myQueue & Q)
    {
        clear();
        c = Q.c;
        s = Q.s;
        f = Q.f;
        r = Q.r;
        ptr = new T[c];
        for(int i=0;i<c;i++)
        {
            ptr[i] = Q.ptr[i];
        }
        return *this;
    }



    T & front()
    {
        if(isEmpty())
        {
            throw "Queue is Empty";
        }
        return ptr[f];
    }

    const T & front() const
    {
        if(isEmpty())
        {
            throw "Queue is Empty";
        }
        return ptr[f];
    }

    void enqueue(const T & el)
    {
        if(s==c)
        {
            if(c==0)
            {
                c=1;
                ptr = new T[c];
            }
            else
            {
                int newc = 2*c;
                T * newMemory = new T[newc];
                int k=0;
                for(int i= f;i<c;i++,k++)
                {
                    newMemory[k] = ptr[i];
                }
                for(int i=0;i<r-1;i++,k++)
                {
                    newMemory[k] = ptr[i];
                }
                delete ptr;
                f = 0;
                r = s;
                c = newc;
                ptr = newMemory;
            }
        }
        ptr[r] = el;
        r = (r+1)%c;
        s++;
        if(s==1)
        {
            f=0;
        }
    }

    void dequeue()
    {
        if(isEmpty())
        {
            throw "Queue is Empty";
        }
        f = (f+1)%c;
        s--;
        if(s==0)
        {
            f=-1;
            r=0;
        }
    }

};

#endif // DynamicQueue_H
