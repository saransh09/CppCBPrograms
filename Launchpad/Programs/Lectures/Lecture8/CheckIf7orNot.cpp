#include<iostream>
using namespace std;

bool Check7(int *a,int s,int e)
{
    if(s>=e)
        return false;

    if(a[s]==7)
    {
        return true;
    }

    Check7(a,s+1,e);
}

int main()
{
    int a[8]= {1,2,3,4,5,6,7,8};
    bool b = Check7(a,0,7);
    if(b==true)
        cout<<"7 Found";
    else
        cout<<"NOT";
    return 0;
}
