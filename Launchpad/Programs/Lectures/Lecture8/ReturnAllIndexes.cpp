#include<iostream>
using namespace std;

int ReturnAll(int *a,int s,int e,int *t,int j)
{
    if(s>e)
        return j;


    if(a[s]==7)
        t[j++]=s;

    ReturnAll(a,s+1,e,t,j);
}

int main()
{
    int a[8] = {1,2,7,7,8,3,2,7};
    int t[8];
    for(int i =0;i<ReturnAll(a,0,7,t,0);i++)
    {
        cout<<t[i]<<' ';
    }
    return 0;
}
