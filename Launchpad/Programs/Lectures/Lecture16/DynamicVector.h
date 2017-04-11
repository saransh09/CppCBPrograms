#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;

template<typename T>
class Vector
{
    T * ptr;
    int size;
    int capacity;
    static void CopyHeapSpace(const T * src,T * dest,int N)
    {

    }

    public:
    Vector(): size(0),capacity(1),ptr(0)
    {
        ptr = new T[capacity];
    }
    Vector(int N,T el) : size(N),capacity(N)
    {
        ptr = new T[N];
        capacity = N;
        size = N;
        for(int i=0;i<N;i++)
        {
            ptr[i]=el;
        }
    }

    Vector(const Vector<T> & b)
    {
        ptr = new T[b.capacity];
        capacity = b.capacity;
        size = b.capacity;
        for(int i=0;i<size;i++)
        {
            ptr[i] = b.ptr[i];
        }
    }

    Vector & operator=(const Vector<T> & b)
    {
        delete ptr;
        ptr = new T[b.capacity];
        size = b.size;
        for(int i=0;i<size;i++)
        {
            ptr[i]=b.ptr[i];
        }
        return *this;
    }

    void clear()
    {
        if(!isempty())
        {
            delete ptr;
            size = capacity = 0;
        }
    }

    ~Vector()
    {
        delete[] ptr;
    }

    T & operator[](int i)
    {
        if(index<0 && index>=s)
        {
            throw "Index out of bounds";
        }
        return ptr[i];
    }

    const T & operator[](int i) const
    {
        if(index<0 && index>=s)
        {
            throw "Index out of bounds";
        }
        return ptr[i];
    }

    int VectorSize() const
    {
        return size;
    }

   /* void clear()
    {
        size=0;
    }*/

    bool isEmpty()
    {
        if(size==0)
            return true;
        else
            return false;
    }

    void pushBack(T ele)
    {
        if(size>=capacity)
        {
            T * temp = new T[2*capacity];
            for(int i=0;i<size;i++)
            {
                temp[i] = ptr[i];
            }
            delete ptr;
            ptr = temp;
            capacity *= 2;
        }
        else
        {
            ptr[size++] = ele;
        }
    }

    void popback()
    {
        if(isEmpty())
        {
            throw "Vector is Empty";
        }
        size--;
    }

    friend ostream & operator << (ostream &,const Vector<T> &)

};

template <typename T>
ostream & operator << (ostream & out,const Vector<T> & B)
{
    for(int i=0;i<s;i++)
    {
        out<<B.ptr[i]<<' ';
    }
    return out;
}

#endif // VECTOR_H
