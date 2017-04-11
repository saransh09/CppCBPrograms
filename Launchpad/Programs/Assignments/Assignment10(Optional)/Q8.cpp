#include<iostream>
using namespace std;

void PrintPossibleSums(int N,int *arr,int s)
{
     if(N==0 && s==1)
    {
        return;
    }

    if(N==0)
    {
        for(int i=0;i<s;i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        return;
    }

    for(int i=1;i<=N;i++)
    {
        arr[s]=i;
        PrintPossibleSums(N-i,arr,s+1);
    }
}

int main()
{
    int x;
    cin>>x;
    cout<<"The Possible Sum Combinations are : "<<endl;
    int a[100];
    PrintPossibleSums(x,a,0);
    return 0;
}
