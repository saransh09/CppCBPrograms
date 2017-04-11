#include<iostream>
using namespace std;

int fib(int n)
{
    if(n==0||n==1)
        return 1;

    int i=1,j=1;
    while(j<n)
    {
        int temp = i;
        i = j;
        j = temp + i ;
    }
    if(n==j)
        return 1;
    else
        return 0;

}


int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}
