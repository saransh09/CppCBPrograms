#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isOpening(char ch)
{
    return (ch == '(' || ch == '{' || ch == '[');
}

bool isClosing(char ch)
{
    return (ch == ')' || ch == '}' || ch == ']');
}

bool areMatching(char ch1, char ch2)
{
    return((ch1=='(' && ch2==')')||(ch1=='[' && ch2==']')||(ch1=='{' && ch2=='}') );
}

int main()
{
    string expression;
    cin >> expression;
    stack<char> s;
    bool isBalanced = true;
    for(int i=0;i<expression.size();i++)
    {
        if(isOpening(expression[i]))
        {
            s.push(expression[i]);
        }
        else
        {
            if(s.empty() || !areMatching(s.top(),expression[i]))
            {
                isBalanced=false;
                break;
            }
            s.pop();
        }
    }
    if(!isBalanced || !s.empty())
    {
        cout<<"Not Balanced"<<endl;
    }
    else
    {
        cout<<"Is Balanced"<<endl;
    }
    return 0;
}
