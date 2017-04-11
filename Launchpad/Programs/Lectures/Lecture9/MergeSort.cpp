#include<iostream>
using namespace std;

void MergeArray(int a[],int n)
{
    int b[n];
    int lb = 0;
    int rb = n-n/2;
    int j=0;

    if(n%2==0)
        rb = rb -1;


while(lb < n/2 && rb < n)
{
    if(a[lb]>=a[rb])
    {
        b[j++] = a[rb++];
    }
    else if(a[lb]<a[rb])
    {
        b[j++] = a[lb++];
    }
}
    if(lb>n/2)
    {
        while(rb<n)
        {
            b[j++] = a[rb++];
        }
    }
    else if(rb>n)
    {
        while(lb<n/2)
        {
            b[j++] = a[lb++];
        }
    }

    for(int i=0;i<n;i++)
    {
        a[i] = b[i];
    }

}


void MergeSort(int a[],int n)
{
    if(n == 1)
        return;

    MergeSort(a,n/2);
    MergeSort(a+(n/2),n-n/2);
    MergeArray(a,n);
    return;
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter an array : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    MergeSort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }



    return 0;
}
