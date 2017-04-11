#include<iostream>
using namespace std;

void PrintPairs(int a[],int N)
{
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if((a[i]+a[j])==N)
            {
                cout<<a[i]<<'\t'<<a[j]<<endl;
            }
        }
    }
}

int main()
{
    cout<<"Enter an array of 10 elements"<<endl;
    int a[10];
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    cout<<endl<<"Enter the number to test : ";
    int N;
    cin>>N;
    cout<<endl;
    PrintPairs(a,N);
}
