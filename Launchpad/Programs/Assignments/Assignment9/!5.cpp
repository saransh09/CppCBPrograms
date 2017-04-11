#include<iostream>
using namespace std;

bool StringAgrees(char *a)
{
    if(*a=='\0')
        return true;

    if(*a!='a')
        return false;

    if(*a=='a')
    {
        if(*(a+1)!='\0' || *(a+1)!='a' || (*(a+1)!='b'  &&  *(a+1)!='b') )
        {
            return false;

        }
    }
}


int main()
{
    cout<<"Enter a string that only contains a's and b's : ";
    char a[100];
    cin.getline(a,100);

    return 0;
}
