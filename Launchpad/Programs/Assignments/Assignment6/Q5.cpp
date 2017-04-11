#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the first String : ";
    int a[127],b[127],s1=0,s2=0;char ch;
    for(int i=0;i<127;i++)
    {
        a[i]=0;
        b[i]=0;
    }
   ch= cin.get();
    int i;
    while(ch!='\n')
    {
        ch=cin.get();
        i = (int)ch;
        a[i] = a[i]+1;
    }
    cout<<endl<<"Enter the Second String : ";
    ch = cin.get();
    while(ch!='\n')
    {
        ch=cin.get();
        i = (int)ch;
        b[i] = b[i]+1;
    }

    for(int i=0;i<127;i++)
    {
        s1+=a[i];
        s2+=b[i];
    }
    if(s1==s2)
    {
        cout<<"They are permutations"<<endl;
    }
    else
        cout<<"They are not permutations of each other"<<endl;
    return 0;
}
