#include<iostream>
using namespace std;

int FindPaths(int b[][1000],int m,int n,int x,int y)
{
    if(b[x][y]!=0)
    {
        return b[x][y];
    }
    if(((x==m-1)&&(y==n))||((x==m)&&(y==n-1)))
    {
        return 1;
    }
    if(x==m&&y<n-1)
    {
        b[x][y] = FindPaths(b,m,n,x,y+1);
        return b[x][y];
    }
    else if(y==n&&x<m-1)
    {
        b[x][y] = FindPaths(b,m,n,x+1,y);
        return b[x][y];
    }
    b[x][y] = FindPaths(b,m,n,x+1,y) + FindPaths(b,m,n,x,y+1);
    return b[x][y];

}

int main()
{
    cout<<"Enter the Order of the matrix : ";
    int m,n;
    cin>>m>>n;
   // PossibleWays(m,n);
    int b[1000][1000];
    FindPaths(b,m-1,n-1,0,0);
    return 0;
}
