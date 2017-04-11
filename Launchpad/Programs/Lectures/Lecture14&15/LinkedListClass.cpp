#include<iostream>
#include "LL.h"
using namespace std;

//Linked List Class, which stores the address of another class to represent itself Node-->Entity



int main()
{
    Node * h = NULL;

    LinkedList L;
    L.InsertAtEnd(10);
    L.InsertAtEnd(20);
    L.InsertAtEnd(30);
    L.InsertAtEnd(40);
    L.PrintList();
    try{
    cout<<"adsasdasdasd"<<endl;
    L[23]=2;
    }
    catch(char * c)
    {
        cout<<c<<endl;
    }
    return 0;
}
