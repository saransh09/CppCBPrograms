#include<iostream>
using namespace std;

void PossibleWords(char *a,char *b,int size)
{
    if(*a=='\0')
    {
        for(int i=0;i<size;i++)
        {
            cout<<b[i]<<' ';
        }
        cout<<endl;
    }

    if(*a=='2')
    {
        b[size] = 'a';
        PossibleWords(a+1,b,size+1);
        b[size] = 'b';
        PossibleWords(a+1,b,size+1);
        b[size] = 'c';
        PossibleWords(a+1,b,size+1);
    }

    if(*a=='3')
    {
        b[size] = 'd';
        PossibleWords(a+1,b,size+1);
        b[size] = 'e';
        PossibleWords(a+1,b,size+1);
        b[size] = 'f';
        PossibleWords(a+1,b,size+1);
    }

}


int main()
{
    char a[100],b[100];
    cin.getline(a,100);
    PossibleWords(a,b,0);
    return 0;
}
