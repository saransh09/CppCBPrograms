#include<iostream>
using namespace std;

int CountWays(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 2;
    }
    else if(n==3)
    {
        return 4;
    }

    return CountWays(n-1) + CountWays(n-2) + CountWays(n-3);
}

int main()
{
    cout<<"Enter the number of steps : ";
    int n;
    cin>>n;
    cout<<CountWays(n);
    return 0;
}
