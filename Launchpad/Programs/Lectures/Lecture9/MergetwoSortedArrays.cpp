#include<iostream>
using namespace std;

void CopyString(int *a,int n,int *c)
{
    if(n==0)  return;

    *c = *a;
    CopyString(a+1,--n,c+1);
}

void MergeSortedArrays(int *a,int *b,int *c,int m,int n)
{
    //cout << m << " " << n << endl;
    if(m==0 && n==0)
    {
        return;
    }


    if(m == 0 && n>0)
    {
        *c = *b;
        MergeSortedArrays(a,b+1,c+1,m,n-1);
        return;
    }
    else if(n==0&&m>0)
    {
        *c = *a;
        MergeSortedArrays(a+1,b,c+1,m-1,n);
        return;
    }


    if(*a>=*b)
    {
        *c = *b;
        MergeSortedArrays(a,b+1,c+1,m,n-1);
    }
    else if(*a<*b)
    {
        *c = *a;
        MergeSortedArrays(a+1,b,c+1,m-1,n);
    }
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<"Enter two arrays : ";
    int a[m],b[n],c[m+n];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    MergeSortedArrays(a,b,c,m,n);
    for(int i=0;i<m+n;i++)
    {
        cout<<c[i]<<' ';
    }
    return 0;
}
