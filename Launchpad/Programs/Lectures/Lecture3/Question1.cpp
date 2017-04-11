#include<iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    int a = 1;    //The Logic is to take the and with 1 i.e in binary and then shift the given number (>>) right shift
    int l,s=0;
    for(int i=0;i<32;i++)
    {
        l = x&a;
        if(l==1)
            s++;

        x = x>>1;
    }
    cout<<s;
    return 0;
}

