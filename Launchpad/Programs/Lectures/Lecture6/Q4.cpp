#include<iostream>
using namespace std;

void append(char A[],char B[])
{
    int i=0;
    while(A[i]!='\0')
    {
        i++;
    }
    int j=0;
    while(B[j]!='\0')
    {
        A[i++]=B[j++];
    }
    A[i++]='\0';
    cout<<A;
}


int main()
{
    char A[100],B[50];
    cin.getline(A,50);
    cin.getline(B,50);
    append(A,B);
    return 0;
}
