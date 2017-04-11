#include<iostream>
using namespace std;

int length(char a[])
{
    int l;
    for(int i=0;a[i]!='\0';i++)
    {
        l++;
    }
    return l;
}

int main()
{
    char a[100];
    int l = length(a);
    cin.getline(a,100);
    for(int i=0;;i++)
    {
        for(int j=0;j<l;j++)
        {

        }
    }
    return 0;
}
