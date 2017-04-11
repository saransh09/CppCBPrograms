#include<iostream>
using namespace std;

int First7(int *a,int s,int e)
{
    int p = -1;

    if(s>=e)
        return p;

    if(a[s]==7)
    {
        p = s;
        return p;
    }


    First7(a,s+1,e);

}

int main()
{
    int a[10] = {1,2,7,8,5,7,5,9,6,7};
    cout<<First7(a,0,9);
    return 0;
}
