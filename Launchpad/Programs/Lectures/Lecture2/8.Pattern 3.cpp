#include<iostream>
using namespace std;

int main()
{
    int n,i=0,j,k=1;
    cout<<"Enter the number of Rows to print";
    cin>> n;
    while(i<n)
    {
        j=1;
        while(j<=(n-i))
        {
            cout<<" ";
            j++;
        }
        k=1;
        while(k<=(2*i+1))
        {
            cout<<k;
            k++;
        }
        i++; cout<<'\n';
    }
}
