#include<iostream>
using namespace std;

void FindSplit(int a[],int n)
{
    int sum2=0,sum1=0,tsum=0;
    for(int i=0,j=1;i<j && j<n;i++,j++)
    {
        sum1+=a[i];
        sum
    }
}


int main()
{
    cout<<"Enter the number of elements in an array"<<endl;
    int n;
    cin>>n;
    cout<<endl<<"Enter "<<n<<" elements of the array"<<endl;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    FindSplit(a,n);
    return 0;
}
