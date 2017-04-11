#include<iostream>
using namespace std;

int CountZeroes(int a,int n)
{
    if(a==0)
    {
        return n;
    }

    if(a%10==0)
        n++;

    CountZeroes(a/10,n);
}

int main()
{
    int a;
    cin>>a;
    cout<<CountZeroes(a,0);
    return 0;
}
