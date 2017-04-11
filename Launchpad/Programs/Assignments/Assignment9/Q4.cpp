#include<iostream>
using namespace std;

void CopyExcluding(char *a,char *b,int i)
{
    int l=0;
    for(int j=0;a[j]!='\0';j++)
    {
        if(j==i)
            j++;

        b[l++]=a[j];
    }
    b[l++]='\0';
}

void PrintPermutes(char *a,char *b,char *c,int l)
{
    if(*b=='\0')
    {
        for(int i=0;i<l;i++)
        {
            cout<<c[i]<<' ';
        }
        cout<<endl;
        return;
    }

    for(int i=0;a[i]!='\0';i++)
    {
        c[0] = a[i];
        CopyExcluding(a,b,i);
        c[l+1]='\0';
        c[l]=*a;
        PrintPermutes(a,b,c,l+1);
    }
}

int main()
{
    cout<<"Enter a string : ";
    char a[100];
    cin.getline(a,100);
    char b[100],c[100];
    return 0;
}
