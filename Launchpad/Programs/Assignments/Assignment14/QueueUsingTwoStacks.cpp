#include<stack>
#include<iostream>
using namespace std;

void Pop(stack<int> & main,stack<int> & aux)
{
    int sm = main.size();
    for(int i=0;i<sm;i++)
    {
        aux.push(main.top());
        main.pop();
    }
    aux.pop();
    for(int i=0;i<sm-1;i++)
    {
        main.push(aux.top());
        aux.pop();
    }
}

int main()
{
    stack<int> main,aux;
    cout<<"Enter the number element to push into the queue : ";
    int n,x;
    cin>>n;
    cout<<"Enter the elements to push into the stack : ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        main.push(x);
    }

    return 0;
}

