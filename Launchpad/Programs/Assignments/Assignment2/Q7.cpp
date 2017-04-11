#include<iostream>
using namespace std;

int main()
{
    cout<<"\nEnter the number of elements in the series";
    int n;
    cin>>n;
    int a;
    cout<<"\nEnter the first number\n";
    cin>>a;
    int i=1,j,b;
    while(i<n)
    {
        cout<<"\nEnter the next number\n";
        cin>>b;

        if(b<a)
        {
            j=0;
        }
        else if(b>a)
        {
            j++;
            if(j==1)
                break;
        }
        i++;
    }

    while(i<n)
    {
        cin>>b;
        if(b>a)
        {
            j=1;
        }
        else if(b<a)
        {
            j++;
            break;
        }
        i++;
    }

    if(j==1)
    {
        cout<<"It is possible";
    }
    else
        cout<<"NOT";
    return 0;
}
