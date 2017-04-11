#include<iostream>
using namespace std;

void Swap(char *a, char *b)
{
    char temp = *a;
    *a=*b;
    *b = temp;
}


void RevString(char *a,int s,int e)
{
    if(s>=e)
        return;

    Swap(a+s,a+e);
    RevString(a,s+1,e-1);
}

int main()
{
    char a[100];
    cout<<"Enter a string : ";
    cin.getline(a,100);
    int l=0;
    while(a[l]!='\0')
    {
        l++;
    }
    RevString(a,0,l-1);
    cout<<endl;
    for(int i=0;i<l;i++)
    {
        cout<<a[i];
    }
    return 0;
}
