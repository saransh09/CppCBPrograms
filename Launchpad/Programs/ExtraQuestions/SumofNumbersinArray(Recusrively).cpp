#include<iostream>
using namespace std;

int ComputeSum(int *a,int x,int y,int sum)
{
    if(x>y)
    {
        return sum;
    }

    sum += a[x];
    ComputeSum(a,x+1,y,sum);

}


int main()
{
    int n;
    cin>>n;
    cout<<"Enter the array :";
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    ComputeSum(a,0,n-1,sum);
    cout<<endl<<sum;
    return 0;
}
