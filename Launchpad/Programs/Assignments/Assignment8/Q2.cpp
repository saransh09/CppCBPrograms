#include<iostream>
using namespace std;

int NoOfZeroes(int x,int t)
{
    if(x==0)
        return t;

    if(x%10==0)
        t++;

    t+= x%10;
    NoOfZeroes(x/10,t);
}

int main()
{
    cout<<"Enter an integer : ";
    int x;
    cin>>x;
    cout<<NoOfZeroes(x,0);
    return 0;
}
