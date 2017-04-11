#include<iostream>
using namespace std;

int main()
{
    int a[5][4];
    cout<<"Input numbers in row order :"<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<endl<<"The output required is"<<endl;
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<a[j][i]<<'\t';
        }
        cout<<endl;
        i++;
        j--;
        if(i<6)
        {
        for(j;j>=0;j--)
        {
            cout<<a[j][i]<<'\t';
        }
        }
        cout<<endl;
    }

    return 0;
}
