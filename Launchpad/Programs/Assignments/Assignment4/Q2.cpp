#include<iostream>
using namespace std;

int main()
{
    char ch=cin.get();
    int c[127];
    int i=0;
    while(i<126)
    {
        c[i]=0;
        i++;
    }
    while(ch!='$')
    {
        c[(int)ch]++;
        ch = cin.get();
    }
    cout<<"The count of respective characters are : "<<endl;
    int j=0;
    while(j<126)
    {
        cout<<(char)j<<'\t'<<c[j]<<endl;
        j++;
    }

    return 0;
}
