#include<iostream>
using namespace std;

int Paths(int b[][1000],int m,int n,int x,int y)
{
    if(b[x][y]!=0)
        return b[x][y];

    if(y!=n && x==m || x!=m && y==n )
    {
        b[x][y] = 1;
        return 1;
    }

    b[x][y] = Paths(b,m,n,x+1,y) + Paths(b,m,n,x,y+1);
    return b[x][y];
}

int main()
{
    int m,n;
    cin>>m>>n;
    int b[1000][1000];
    cout<<endl<<Paths(b,m-1,n-1,0,0);
    return 0;
}
