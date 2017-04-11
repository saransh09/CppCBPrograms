#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter a number";
    int x,s=0,a,b;
    cin>>x;
    a=x;
    while(a>0)
    {
        b=a%10;
        a/=10;
        s+=(b*b*b);
    }
    if(s==x)
    {
        cout<<"Armstrong number";
    }
    else
        cout<<"NOT";
    return 0;
}
