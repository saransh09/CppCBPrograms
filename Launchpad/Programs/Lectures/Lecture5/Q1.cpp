#include<iostream>
using namespace std;

long long int fact(int x)
{
    int i=1;long long int f=1;
    for(i=1;i<=x;i++)
    {
        f*=i;
    }
    return f;
}

long long int nCr(int n, int r)
{
    long long int a,b,c;
    a = fact(n);
    b = fact(r);
    c = fact(n-r);
    long long int d = a/c;
    long long int e = d/b;
    return e;
}

int main()
{
    int x,n,r;
    cout<<"Enter the number whose factorial is to be calculated"<<endl;
    cin>>x;
    cout<<fact(x)<<endl;
    cout<<"Enter the value of n & r respectively"<<endl;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;

    return 0;
}
