#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a>b&&a>c)
    {
        cout<< "Largest is : " << a;
    }
    else if(b>a && b>c)
    {
        cout<< "Largest is : " << b;
    }
    else
        cout<< "Largest is : " << c;
    return 0;
}
