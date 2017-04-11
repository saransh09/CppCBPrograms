#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int a;
    cin>>a;
    int i,j,k=0;
    while(k<a)
    {
        i=a;
        while(i>k)
        {
            j=i%2;
            i/=2;
        }
        k+=2;
        cout<<j;
    }
    return 0;
}

