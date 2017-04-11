#include<iostream>
using namespace std;

void CheckRev(char *a,char *b,int s,int e,int l)
{
    if(s>l)
        cout<<"YUPPPP!";

    if(a[s]!=b[e])
        cout<<"Naaah";

    CheckRev(a,b,s+1,e-1,l);

}

int main()
{
    cout<<"Enter two strings : ";
    char a[100],b[100];
    cin.getline(a,100);
    cin.get();
    cin.getline(b,100);
    int l1=0,l2=0;
    while(a[l1]!='\0')
        l1++;
    while(b[l2]!='\0')
        l2++;
    if(l1!=l2)
    {
            cout<<endl<<"Naaah";
    }
    else
    {
        CheckRev(a,b,0,l1-1,l1-1);
    }
    return 0;
}
