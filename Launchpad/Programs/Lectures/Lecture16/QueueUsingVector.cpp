#include<iostream>
#include"DynamicQueue.h"
using namespace std;

int main()
{
    myQueue<int> Q;
    for(int i=0;i<10;i++)
    {
        Q.enqueue(i);
    }
    myQueue<int> Q2 = Q;
    Q.clear();
    Q = Q2;
    while(!Q2.isEmpty())
    {
        cout<<Q2.front()<<endl;
        Q2.dequeue();
    }
    while(!Q.isEmpty())
    {
        cout<<Q.front()<<endl;
        Q.dequeue();
    }
    cout<<Q.size()<<endl;
    cout<<Q2.size()<<endl;
    return 0;
}
