#include<iostream>
using namespace std;

int main()
{
    int n,i=1,a,b,s,maxi,mini;
    float mean;
    cin >> n;
    cout<<"Enter first number";
    cin>> a;
    s = maxi = mini = a;

    while(i<n)
    {
        cin>>b;
        if(b>maxi)
            maxi = b;
        else if(b<mini)
            mini = n;

        s+=b;
        i++;
    }
    mean = s/n;
    cout << "MAX" << maxi;
    cout << '\n' << "MIN" << mini;
    cout << '\n' << "MEAN" << maxi;
    return 0;
}
