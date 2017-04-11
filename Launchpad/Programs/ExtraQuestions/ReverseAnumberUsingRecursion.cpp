#include<iostream>
using namespace std;

int CountDigits(int a,int digits)
{
    if(a==0)
        return digits;
    else
        digits++;

    CountDigits(a/10;digits);
}

int ReverseNumber(int a,int d,int r)
{
    if(a==0)
        return r;


}


int main()
{
    int a;
    cin>>a;
    int d = CountDigits(a);
    ReverseNumber()
    return 0;
}
