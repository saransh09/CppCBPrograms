#include<iostream>
using namespace std;

void rev(int x)
{
    int r=0,d;
    while(x>0)
    {
        d = x%10;
        r = r*10 + d;
    }
    cout<<r<<endl;

}



int main()
{
    int n;
    cin>>n;
    for(int i = n;i>0;i/=10)
    {
        cout<<i%10;
    }


    return 0;
}

