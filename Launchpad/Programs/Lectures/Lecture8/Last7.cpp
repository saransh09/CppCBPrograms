#include<iostream>
using namespace std;

int Last7(int *a,int s,int e)
{
    if(e<=s)
        return -1;

    if(a[e]==7)
        return e;

    Last7(a,s,e-1);
}

int main()
{
    int a[8] = {1,4,7,1,4,7,1,8};
    cout<<Last7(a,0,7);

    return 0;
}
