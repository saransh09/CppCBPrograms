#include<iostream>
using namespace std;

int len(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return i;
}

int main()
{
    cout<<"Enter the number till the place the string to be rotated"<<endl;
    int n,i;
    cin>>n;
    char a[100];
    cin.getline(a,100);
    cin.getline(a,100-n);
    for(i=len(a)-1;i>0;i--)
    {
        a[i+n-1] = a[i];
    }

    /*int l = len(a)-1;
    int j=0;
    for(i=l-n;i<l;i++)
    {
        a[j] = a[i];
        j++;
    }
    a[l-n+1]='\0';
    cout<<endl<<a;
    return 0;
}
