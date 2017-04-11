#include<iostream>
using namespace std;

int main()
{
    //cout<<(char)(65 + (char)true)<<endl;

    int a = 10;
    int c = a++;
    int d = ++a;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<a<<endl;
    (1 && (++a));
    cout<<a<<endl;
    (0 && (++a));
    cout<<a<<endl;

    return 0;
}
