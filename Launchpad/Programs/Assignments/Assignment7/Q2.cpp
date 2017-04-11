#include<iostream>
using namespace std;
int n;

int main()
{
    cout<<"Enter the order of the square matrix : ";
    cin>>n;
    cout<<endl<<"Enter a matrix of 0's and 1's"<<endl;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    int t=1, ar[n],ac[n];

    for(int i=0;i<n;i++)
    {
        ar[i]=1;
        ac[i]=1;
    }

    for(int i=0;i<n;i++)
    {
        t=1;
        for(int j=0;j<n;j++)
        {
          t = t & a[i][j];
        }
        if(t==0)
        {
            ar[i]= 0;
        }
    }

    for(int j=0;j<n;j++)
    {
        t=1;
        for(int i=0;i<n;i++)
        {
           t = t & a[i][j];
        }
        if(t==0)
        {
            ac[j] = 0;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(ar[i]==0)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j] = 0;
            }
        }

        if(ac[i]==0)
        {
            for(int j=0;j<n;j++)
            {
                a[j][i] = 0;
            }
        }
    }

    cout<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<< a[i][j] << ' ';
        }
        cout<<endl;
    }
    return 0;
}
