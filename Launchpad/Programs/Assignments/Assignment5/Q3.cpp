#include<iostream>
using namespace std;

void PrintPairs(int a[],int n)
{
    int i=0,j=9;
    while(i<j)
    {
        if((a[i]+a[j])>n)
            j--;
        else if((a[i]+a[j])<n)
            i++;
        else if((a[i]+a[j])==n)
        {
            cout<<a[i]<<'\t'<<a[j]<<endl;
            i++;
            j--;
        }
    }
}


int main()
{
    cout<<"Enter a sorted array of 10 elements"<<endl;
    int a[10];
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    cout<<endl<<"Enter the number n : ";
    int n;
    cin>>n;
    cout<<endl;
    PrintPairs(a,n);
    return 0;
}
