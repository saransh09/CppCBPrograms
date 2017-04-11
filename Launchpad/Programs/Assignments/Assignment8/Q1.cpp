#include<iostream>
using namespace std;

int ComputeSum(int a[],int x,int y,int sum)
{
    if(x>y)
    {
        return sum;
    }

    sum+=a[x];
    ComputeSum(a,x+1,y,sum);

}

int main()
{
    cout<<"Enter the number of terms you want in the array : ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the numbers to fill in the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The sum is : "<<ComputeSum(a,0,n-1,0);
    return 0;
}
