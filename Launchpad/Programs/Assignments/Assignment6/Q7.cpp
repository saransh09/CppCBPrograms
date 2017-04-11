#include<iostream>
#include<cmath>
using namespace std;

int htoi(char *a)
{
    int i=0,j,k=0,sum=0;
    while(a[i]!='\0')
    {
        i++;
    }
    for(i;i>0;i--)
    {
        if(a[i]=='0')
            j=0;
        else if(a[i]=='1')
            j=1;
        else if(a[i]=='2')
            j=2;
        else if(a[i]=='3')
            j=3;
        else if(a[i]=='4')
            j=4;
        else if(a[i]=='5')
            j=5;
        else if(a[i]=='6')
            j=6;
        else if(a[i]=='7')
            j=7;
        else if(a[i]=='8')
            j=8;
        else if(a[i]=='9')
            j=9;
        else if(a[i]=='A')
            j=10;
        else if(a[i]=='B')
            j=11;
        else if(a[i]=='C')
            j=12;
        else if(a[i]=='D')
            j=13;
        else if(a[i]=='E')
            j=14;
        else if(a[i]=='F')
            j=15;

        sum = sum + pow(16,k)*j;
        k++;
    }
    return sum;
}


int main()
{
    cout<<"Enter a  hexadecimal string : ";
    char a[100];
    cin.getline(a,100);
    cout<<htoi(a);
    return 0;
}
