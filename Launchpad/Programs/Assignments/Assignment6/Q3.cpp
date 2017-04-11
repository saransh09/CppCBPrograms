#include<iostream>
using namespace std;

int main()
{
    char a[100];
    cout<<"Enter a string : ";
    cin.getline(a,100);
    int l=0;
    for(int i=0;i<l;i++)
    {
        l++;
    }
    cout<<endl;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<a[j];
        }
        cout<<endl;
    }
    return 0;
}
