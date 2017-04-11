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
    cout<<"Enter the number of strings you want to enter : ";
    int n;
    cin>>n;
    char a[100],b[100];
    int l1,l2;
     cin.getline(a,100);
        l1=len(a);
    for(int i=0;i<n;i++)
    {

        cin.getline(b,100);
        l2=len(b);
        int j;
        if(l2>l1)
        {
            for(j=0;j<l2;j++)
                a[j]=b[j];

            a[j] = '\0';
            l1 = l2;
        }
    }

    cout<<a;
    return 0;
}
