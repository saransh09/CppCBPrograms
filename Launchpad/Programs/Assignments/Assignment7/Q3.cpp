#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the order dimensions of the array in m x n format : ";
    int m,n;
    cin>>m>>n;
    cout<<endl<<"Enter the elements"<<endl;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    int maxi,ma,ar[m];

    for(int i=0;i<m;i++)
    {
        maxi = a[i][0];
        ma = 0;
        for(int j=0;j<n;j++)
        {
            if(a[i][j]>maxi)
            {
                maxi = a[i][j];
                ma = j;
            }
        }
        ar[i] = ma;
    }

    int mini,mi,ac[n];

    for(int i=0;i<n;i++)
    {
        mini = a[0][i];
        for(int j=0;j<m;j++)
        {
            if(a[j][i]<mini)
            {
                mini = a[j][i];
                mi = j;
            }
        }
        ac[i] = mi;
    }

    int u;
    if(m>n)
        u=n;
    else
        u=m;

    int saddle[u];

    for(int i=0;i<u;i++)
    {
        saddle[i]=-1;
    }


    for(int i=0;i<m;i++)
    {
        if(a[ar[i],i]==a[i,ac[i]])
            saddle[i] = 0;
    }

    int counter=0;

    for(int i=0;i<u;i++)
    {
        if(saddle[i]==0)
        {
            cout<<"The saddle point is at : "<<i+1<<','<<ac[i]+1<<endl;
            counter++;
        }

    }

     if(counter==0)
            cout<<"No saddle point";




    return 0;
}
