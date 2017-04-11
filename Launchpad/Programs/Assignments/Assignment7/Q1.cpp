#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the number of rows you want in the square matrix to be generated : ";
    int n;
    cin>>n;
    char a[n][n];
    if(n%2==1)
    {
        int x=0,y=0;
        for(int i=n-1,j=n-1;i!=n/2 && j!=n/2;i--,j--)
        {
            while(y<=j)
            {
                a[x][y]='O';
                y++;
            }
            y--;
            while(x<=i)
            {
                a[x][y]='O';
                x++;
            }
            x--;
            while(j>=0)
            {
                a[i][j]='O';
                j--;
            }
            j++;
            while(i>=0)
            {
                a[i][j]='O';
                j--;
            }
        }
    }
    else
    {
        for(int i=0,j=0;i!=n/2 && j!=n/2-1;i++)
        {

        }
    }
    return 0;
}
