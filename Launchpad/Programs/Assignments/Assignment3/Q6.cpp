#include<iostream>
using namespace std;

int main()
{
    int i,j,k,l,m;
    for(i=1;i<=3;i++)
    {
        for(j=0;j<i;j++)
        {
            cout<<'*';
        }
        cout<<' ';
        for(k=3;k>=i;k--)
        {
            cout<<'*';
        }
        cout<<' ';
        for(l =3;l>=i;l--)
        {
            cout<<'*';
        }
        cout<<' ';
        for(m=0;m<i;m++)
        {
            cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}
