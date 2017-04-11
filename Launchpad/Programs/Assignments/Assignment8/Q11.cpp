#include<iostream>
using namespace std;

void Change(char *a,char *b)
{
    if(*a=='\0')
        {

            return;
        }

    if(*a=='p'&&*(a+1)=='i')
    {
        *b = '3';
        *(b+1) = '.';
        *(b+2) = '1';
        *(b+3) = '4';
        *(b+4) = '\0';
        Change(a+2,b+4);
    }
    else
    {
        *b = *a;
        *(b+1) = '\0';
        Change(a+1,b+1);
    }
}

int main()
{
    char a[100],b[100];
    cin.getline(a,100);
    Change(a,b);
    cout<<endl<<b;
    return 0;
}
