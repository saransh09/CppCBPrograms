#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int a,c;
    float b,d;
    cin>>a;
    b = sqrt(a);
    c = sqrt(a);
    d = b-c;
    if(d>0.5)
        cout<<c+1;
    else if(d<=0.5)
        cout<<c;
    return 0;
}
