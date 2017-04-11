#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    cout<<"Enter the number whose square root is to be found\n";
    float n;
    cin>>n;
    float x1 = n/2,x2= x1 - (((x1*x1)-n)/(2*x1));
    while(abs(x2-x1)>0.00001)                         //The precision is to 5 Decimal places
    {
        x1 = x2;
        x2= x1 - (((x1*x1)-n)/(2*x1));
    }
    cout<<x2;
    return 0;
}
