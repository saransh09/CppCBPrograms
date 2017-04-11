#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0)
        return 1;

    return n*fact(n-1);
}

int fib(int n)
{
    if(n==1||n==2)
        return 1;

    return fib(n-1)+fib(n-2);
}

int gcd(int a, int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);

}

void PrintArrayVersion1(int *arr, int N)
{
    if(N==0)
        return;
    cout<<*arr<<" ";
    PrintArrayVersion1(arr+1,N-1);
    return;
}

int LargestInArray(int *arr,int N)
{
    if(N==1)
        return *arr;

    int subans = LargestInArray(arr+1,N-1);
    if(subans>*arr)
        return subans;
    else
        return *arr;
}


int main()
{
    cout<<fact(7)<<endl<<fib(10)<<gcd(14,2);

    return 0;
}
