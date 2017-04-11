#include<iostream>
using namespace std;

void PrintSubsetsWithSum(int *a,int *sol,int n,int size,int sum)
{
    if(n==0&&sum==0)
    {
        for(int i=0;i<size;i++)
        {
            cout<<sol[i]<<' ';
        }
        cout<<endl;
        return;
    }

    if(n==0)
    {
        return;
    }

    PrintSubsetsWithSum(a+1,sol,n-1,size,sum);
    sol[size]=*a;
    PrintSubsetsWithSum(a+1,sol,n-1,size+1,sum-*(a) );
}

int main()
{
    int n;
    cin>>n;
    int a[n],sol[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    PrintSubsetsWithSum(a,sol,n,0,5);
    return 0;
}
