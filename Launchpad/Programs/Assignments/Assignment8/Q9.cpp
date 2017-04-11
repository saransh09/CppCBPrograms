#include<iostream>
using namespace std;

void RemoveDuplicates(char *a,char *p)
{
    if(*a=='\0')
    {
        *(p+1)='\0';
        return;
    }
    if(*(p+1)==*p)
    {
        while(*p==*a)
        {
            RemoveDuplicates(a,p+1);
        }
        RemoveDuplicates(a+1,p);
        *a = *p;
    }

}

int main()
{
    char a[100]="aaabccdeeeffg";
    char *p=a;
    RemoveDuplicates;
    cout<<a;
    return 0;
}
