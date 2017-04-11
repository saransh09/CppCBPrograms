#include<iostream>
using namespace std;

int main()
{
    int n,i=2,flag=0;
    cin>>n;
    if(n<2)
    {
        cout<<"Not prime";
    }
    else
    {
        while(i<=(n/2))
        {
            if(n%i==0)
            {
                cout << "Not prime";
                flag = 1;
                break;
            }
            else
            {
                i++;

            }
        }
        if(flag==0)
        {
            cout<<"Prime";
        }
    }
    return 0;
}
