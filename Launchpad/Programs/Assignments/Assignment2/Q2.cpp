#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cout<<"Enter the First Number\n";
    cin>>a;
    cout<<"\nEnter the Second Number\n";
    cin>>b;
    cout<<"\nEnter the character\n";
    char c;
    cin>>c;
    if(c=='+')
        cout<<a+b;
    else if(c=='-')
        cout<<a-b;
    else if(c=='*')
        cout<<a*b;
    else if(c=='/')
        cout<<(float)a/b;
    else if(c=='%')
        cout<<a%b;
    else
        cout<<"Invalid Entry";
}
