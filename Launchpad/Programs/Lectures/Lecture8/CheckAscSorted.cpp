#include<iostream>
using namespace std;

bool CheckAsc(int *a,int s,int e)
{
    if(s>=e)
        return true;

    if(a[s+1]<a[s])
        return false;

    CheckAsc(a,s+1,e);
}

int main()
{
    int a[8] = {1,2,3,4,5,6,7,8};
    bool b = CheckAsc(a,0,7);

    if(b==true)
        cout<<"In Ascending order"<<endl;
    else
        cout<<"NOT";
    return 0;
}
