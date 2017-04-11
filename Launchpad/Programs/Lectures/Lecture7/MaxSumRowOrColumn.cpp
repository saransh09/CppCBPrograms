#include<iostream>
using namespace std;

int main()
{
    int sum1=0,sum2=0,s=0,r=0,c=0;
    int a[5][5];
    cout<<"Enter the elements of a matrix row wise :"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        s=0;
        for(int j=0;j<5;j++)
        {
            s = s+a[i][j];
            if(s>sum1)
               {
                 r=i;
                 sum1 = s;
               }
        }

    }
    for(int i=0;i<5;i++)
    {
        s=0;
        for(int j=0;j<5;j++)
        {
            s = s+a[j][i];
            if(s>sum2)
            {
                c = i;
                sum2 = s;
            }

        }
    }

    if(sum1>sum2)
    {
        cout<<r+1<<" row"<<endl;
    }
    else
    {
        cout<<c+1<<" column"<<endl;
    }
    return 0;
}
