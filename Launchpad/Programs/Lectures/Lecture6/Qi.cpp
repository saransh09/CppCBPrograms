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

int Swap(char *a, char *b)
{
    char t = *a;
    *b = *a;
    *a = t;
}


void Reverse(char a[])
{
    int l = len(a)-1;
    int i=0;
    while(i<l)
    {
        Swap(&a[i],&a[l]);
        i++;
        l--;
    }
}


int main()
{
    char a[100];
    cin.getline(a,100);
    Reverse(a);
    cout<<"Reversed Array is : "<<a;
}
