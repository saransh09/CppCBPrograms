#include<iostream>
#include<stack>
#include<string>

/*
Done 1.	Print operands as they arrive.

Done 2.	If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.

Done 3.	If the incoming symbol is a left parenthesis, push it on the stack.

Done 4.	If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.

Done 5.	If the incoming symbol has higher precedence than the top of the stack, push it on the stack.

Done 6.	If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator.

Done 7.	If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.

Done 8.	At the end of the expression, pop and print all operators on the stack. (No parentheses should remain.)
*/

using namespace std;

bool IsOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
    {
        return true;
    }
    else
        return false;
}

bool HighP(char ch)
{
    if(ch=='/'||ch=='*')
        return true;

    else
        return false;
}

bool LowP(char ch)
{
    if(ch=='+'||ch=='-')
        return true;

    else
        return false;
}


int main()
{
    string s;
    cin>>s;
    char postfix[100];
    int j=0;
    stack<char> S;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<=90&&s[i]>=65)
        {
            postfix[j++]=s[i];
            continue;
        }
        else if(IsOperator(s[i]&&(S.empty()||(S.top()=='('))))
        {
            S.push(s[i]);
            continue;
        }
        else if(s[i]=='(')
        {
            S.push(s[i]);
            continue;
        }
        else if(s[i]==')')
        {
            while(S.top()!='(')
            {
                postfix[j++]=S.top();
                S.pop();
            }
            continue;
        }
        else if(IsOperator(s[i]))
        {
            if(HighP(s[i])&&!HighP(S.top()))
            {
                S.push(s[i]);
                continue;
            }
            else if((HighP(s[i])&&HighP(S.top()))||(LowP(s[i])&&LowP(S.top())))
            {
                postfix[j++]=S.top();
                S.pop();
                S.push(s[i]);
                continue;
            }
            else if(LowP(s[i])&&HighP(S.top()))
            {
                while(LowP(s[i])&&!HighP(S.top()))
                {
                    postfix[j++]=S.top();
                    S.pop();
                }
                S.push(s[i]);
                continue;
            }
        }
    }
    while(S.size()!=0)
    {
        postfix[j++]=S.top();
        S.pop();
    }

    postfix[j++]='\0';
    int k=0;
    while(postfix[k]!='\0')
    {
        cout<<postfix[k++];
    }
    return 0;
}
