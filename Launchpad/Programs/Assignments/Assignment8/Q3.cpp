#include<iostream>
using namespace std;

int pow(int a,int x)
{
    if(x==1)
        return a;

    if(x%2==1)
        return a*pow(a,x/2)*pow(a,x/2);
    else
        return pow(a,x/2)*pow(a,x/2);
}

int ReverseNumber(int x, int t,int i)
{

    if(x==0)
        return t;

    t += ((x%10) * pow(10,i++));
    ReverseNumber(x/10,t,i);
}


int main()
{
    cout<<"Enter a number : ";
    int x;
    cin>>x;
    cout<<ReverseNumber(x,0,0);
    return 0;
}
