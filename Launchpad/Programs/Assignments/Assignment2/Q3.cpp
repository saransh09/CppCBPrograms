#include<iostream>
using namespace std;

int main()
{
    cout<<"Please Enter a character\n";
    char a;
    cin>>a;
    if(a>=65&&a<=90)
        cout<<"Uppercase";
    else if(a>=97&&a<=122)
        cout<<"Lowercase";
    else
        cout<<"Invalid Entry";
    return 0;
}
