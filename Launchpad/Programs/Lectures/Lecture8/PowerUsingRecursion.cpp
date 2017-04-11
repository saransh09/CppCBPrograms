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

int main()
{

    cout<<pow(2,5);

    return 0;
}
