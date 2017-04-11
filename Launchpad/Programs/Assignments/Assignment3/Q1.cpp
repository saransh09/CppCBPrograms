#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a = 1;
    int l,s=0;
    for(int i=1;i<32;i++)
    {
        l = n&a;
        if(l==1)
            s++;

        n>>=1;
    }
    cout<<s;
    return 0;
}
