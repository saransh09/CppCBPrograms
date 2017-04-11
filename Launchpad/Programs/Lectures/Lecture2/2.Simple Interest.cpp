#include<iostream>
using namespace std;

int main()
{
    int p,r,t;
    float si;
    cin >> p >> r >> t;
    si = (float)(p*r*t)/100;   //or if Type casting is not to be used then use 100.0 in place of 100
    cout << "The Simple interest is : "<<si;
    return 0;
}
