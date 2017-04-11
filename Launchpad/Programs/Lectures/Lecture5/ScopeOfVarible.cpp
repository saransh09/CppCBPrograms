#include<iostream>
using namespace std;

void printC2Ftable(int b, int e, int s)
{
    for(int i=b;i<=e;i+=s)
    {
        cout<<i<<'\t'<<(5/9.0)*(i-32)<<endl;
    }
}


int main()
{
   printC2Ftable(0,100,20);
}
