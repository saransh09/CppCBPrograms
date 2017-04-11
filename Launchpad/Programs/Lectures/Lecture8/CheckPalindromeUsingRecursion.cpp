#include<iostream>
using namespace std;

bool CheckP(int *a,int s,int e)
{
    if(s>=e)
        return true;

    if(a[s]!=a[e])
        return false;

    CheckP(a,s+1,e-1);

}

int main()
{
    int a[4] = {1};
    bool t = CheckP(a,0,0);
    if(t==true)
        cout<<"Is a palindrome";
    else
        cout<<"naaaah";
    return 0;
}
