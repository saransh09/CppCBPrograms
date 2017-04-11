#include<iostream>
using namespace std;

int main()
{
    char ch,prev=0;
    int cc=0,lc=1,wc=0;
    ch = cin.get();
    while(ch!='$')
    {
        while(ch!=' ' && ch!='\t' && ch!='\n' && ch!='$')
        {
            cc++;
            prev = ch;
            ch = cin.get();
        }
        if(ch=='\n')
        {
            lc++;
            wc++;
            ch = cin.get();
        }
        if(ch==' ')
        {
            while(ch==' '&&ch!='$')
            {
                if(((prev!=' '&& prev!='\t' && prev!='\n') && (ch==' '&& ch=='\t' && ch=='\n')) || ((prev!=' '&& prev!='\t' && prev!='\n') && (ch=='$') ))

                {
                    wc++;
                }
                ch = cin.get();
            }
        }

    }

    cout<<cc<<'\t'<<wc<<'\t'<<lc;
    return 0;
}
