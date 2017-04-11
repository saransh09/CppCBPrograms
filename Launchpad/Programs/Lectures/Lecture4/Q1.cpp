#include<iostream>
using namespace std;

int main()
{
    char a = cin.get();
    int cn=0,cs=0,ce=0,cw=0,ch=0,cv=0;
    while(a!='$')
    {
        if(a=='N')
        {
            cn++;
        }
        if(a=='S')
        {
            cs++;
        }
        if(a=='E')
        {
            ce++;
        }
        if(a=='W')
        {
            cw++;
        }
        a = cin.get();
    }

int ch1=ce-cw, ch2 = cw-ce,  cv1 = cn-cs,  cv2 = cs-cn;
    if(ce>cw)
    {
        while(ch1>0)
        {
            cout<<'E';
            ch1--;
        }
    }


    if(cn>cs)
    {
        while(cv1>0)
        {
            cout<<'N';
            cv1--;
        }
    }

    if(cs>cn)
    {
        while(cv1>0)
        {
            cout<<'S';
            ch1--;
        }
    }

    if(cw>ce)
    {
        while(ch2>0)
        {
            cout<<'W';
            ch2--;
        }
    }

    return 0;
}
