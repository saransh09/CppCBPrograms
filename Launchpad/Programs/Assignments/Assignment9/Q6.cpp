
#include<iostream>
using namespace std;

void Generate(int s,int e,int i)
{
    if(i<s||i>e)
        return;

    cout<<i<<'\t';
    for(int j=0;j<10;j++)
    {
        Generate(s,e,10*i+j);
    }
}

int main()
{
    for(int i=1;i<10;i++)
    {
        Generate(0,1000,i);
    }
    return 0;
}
