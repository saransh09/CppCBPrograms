#include<iostream>
using namespace std;

void PrintPairs(int a[],int x)
{
    for(int i=0;i<=4;i++)
    {
        for(int j=i+1;j<=4;j++)
        {
            if((a[i]+a[j])==x)
            {
                cout<<a[i]<<'\t'<<a[j]<<endl;
            }
        }
    }
}

int main()
{
    cout<<"Enter 5 elements of the array";
    int a[5];
    for(int i=0;i<=4;i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    PrintPairs(a,x);
    return 0;
}
