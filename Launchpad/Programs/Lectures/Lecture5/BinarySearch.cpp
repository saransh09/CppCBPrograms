#include<iostream>
using namespace std;

int BinarySearch(int b, int l,int a[], int e)
{
    int m = (b+l)/2;
    while(b<l)
    {
        if(a[m]==e)
        {
            return m;
        }
        else if(a[m]>e)
        {
            l = m-1;
        }
        else if(a[m]<e)
        {
            b = m+1;
        }
        m=(b+l)/2;
    }
    return -1;
}

int main()
{
    cout<<"Enter the number of elements in the array : ";
    int n;
    cin>>n;
    int a[n];
    cout<<endl<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++)
    {
         cin>>a[i];
    }
    int b=0;
    cout<<"The index at which the element is present is : (-1 if not found) "<<BinarySearch(b,n-1,a,4)<<endl;
    return 0;
}
