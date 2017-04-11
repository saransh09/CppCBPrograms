#include<iostream>
using namespace std;

int main()
{
int n,i=1,j=1,s=1;
cin>>n;
while(i<=n)
{
    j=1;
    while(j<=i)
    {
        cout<< s++ << '\t';
        j++;
    }
    cout<<'\n';
    ++i;
}

}
