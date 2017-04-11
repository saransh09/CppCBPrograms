#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the length of the arrays: "<<endl;
    cin>>n;
    int a[n],b[n];
    cout<<"Enter the elements in the array 1"<<endl;
    int i,j;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the elements in the array 2"<<endl;
    for(j=0;j<n;j++)
    {
        cin>>b[j];
    }
    int c[2*n],x=0,y=0,z=0;
    while(x<n&&y<n)
        {
            if(a[x]<b[y])
            {
                c[z++]=a[x++];
            }
            else if(a[x]>b[y])
            {
                c[z++]=b[y++];
            }
        }
        if(x<n-1)
        {
            c[z++]=a[x++];
        }
        if(y<n-1)
        {
            c[z++]=b[y++];
        }
        cout<<"The median elements are : "<<c[n-1]<<'\t'<<c[n]<<endl;
    return 0;
}
