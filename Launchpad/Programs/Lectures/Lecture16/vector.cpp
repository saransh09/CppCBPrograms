#include<iostream>
#include"DynamicVector.h"

using namespace std;

int main()
{
    Vector<int> a(10,1);
    a[2] = 5;
    cout<<a[2];
    return 0;
}
