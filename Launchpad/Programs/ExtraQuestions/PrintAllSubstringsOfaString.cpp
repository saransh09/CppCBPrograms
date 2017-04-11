#include<iostream>
using namespace std;

int main()
{
    char a[100];
    int l=0;
    cin.getline(a,100);
    for(int i=0;a[i]!='\0';i++)
    {
        l++;
    }
    for(int i=0;i<l;i++)
    {
        for(int j=i;j<l;j++)
        {
            cout<<a[j];
        }
        cout<<endl;
    }
    return 0;
}
