#include<iostream>
using namespace std;


void PrintSubStrings(char a[],char sol[],int l)
{
    if(*a=='\0')
    {
        for(int i=0;i<l;i++)
        {
            cout<<sol[i];
        }
        cout<<endl;
        return;
    }
    sol[l+1]='\0';
    PrintSubStrings(a+1,sol,l);
    sol[l]=*a;
    PrintSubStrings(a+1,sol,l+1);
}

int main()
{
    cout<<"Enter an array : ";
    char a[100],b[100];
    cin.getline(a,100);
    PrintSubStrings(a,b,0);
    return 0;
}
