#include<iostream>
using namespace std;

int main()
{
    int i,j,k;
    for(i=0;i<5;i++)
    {
        for(j=5;j>i;j--)
        {
            cout<<'*';
        }
        for(k=1;k>=i;k++)
        {
            cout<<'p';
        }/*
        for(j=0;j>i-1;j++)
        {
            cout<<' ';
        }
        for(j=4;j<i;j--)
        {
            cout<<'*';
        }*/
        cout<<endl;

    }
    return 0;
}
