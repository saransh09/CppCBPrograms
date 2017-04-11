#include<iostream>
#include<cmath>
using namespace std;

int MinimumDenomination(int *a,int n,int s)
{
    if(s<0)
        return -1;

    for(int i=0;i<n;i++)
    {
        if(s==a[i])
            return 1;
    }

    int ans = -1;
    for(int i=0;i<n;i++)
    {
        int subans = MinimumDenomination(a,n,s-a[i]);
        if(subans!=-1)
        {
            if(ans==-1 || ans>subans)
            {
                ans = subans;
            }
        }
    }

    if(ans==-1)
        return -1;

    else return ans+1;

}

int main()
{
    cout<<"Enter the number of denominations : ";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s;
    cin>>s;
    cout<<endl<<MinimumDenomination(a,n,s);
    return 0;
}
