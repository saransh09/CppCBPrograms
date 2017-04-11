#include<iostream>
#include<stack>
#include<string>
using namespace std;

int presidence(char ch)
{
    if(ch=='+' || ch =='-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
}

int main()
{
    stack<char> S;
    string input,output;
    cin>>input;


    return 0;
}
