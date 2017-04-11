#include<iostream>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void compress(char *a)
{
    int i,j=0;
    while(a[i]!='\0')
    {
        while(a[j]!='0')
        {
            j++;
        }

    }
}

int main()
{
    cout<<"Enter a string : ";
    char a[100];
    cin.getline(a,100);
    compress(a);
    return 0;
}
