#include<iostream>
using namespace std;


int length(char *a)
{
    int i=0;
    while(a[i]!='\0')
        i++;

    return i;
}

void PrintAll(char *sol,char* num)
{
    if(*num == '\0')
    {
        cout<<sol<<endl;
        return;
    }

    int len = length(sol);
    sol[len] = num[0] - '0' + 'A';
    sol[len+1] = '\0';
    PrintAll(sol,num+1);

    if(num[1]!='\0')
    {
        int x = (num[0]-'0')*10 + (num[1]-'0');
        if(x<=25)
        {
            sol[len] = x + 'A';
            sol[len+1] = '\0';
            PrintAll(sol,num+2);
        }
    }
}

int main()
{
    cout<<"Enter a number : ";
    char sol[100],num[100];
    sol[0]='\0';
    cin.getline(num,100);
    PrintAll(sol,num);
    return 0;
}
