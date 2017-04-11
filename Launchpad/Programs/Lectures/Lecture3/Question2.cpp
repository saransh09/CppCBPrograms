#include<iostream>
using namespace std;



int main()
{
    int n;
    cin>>n;
    int j;
    for(int i=n-1;i>=0;i--)
    {

        for(j = 65;j<=65+i;j++)
        {
            cout<<(char)j;
        }
        for(j = 65+i;j>=65;j--)
        {
            cout<<(char)j;
        }
        cout<<endl;
    }
    return 0;
}
