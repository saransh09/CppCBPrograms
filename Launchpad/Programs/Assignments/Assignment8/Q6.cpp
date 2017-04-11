#include<iostream>
#include<cmath>
using namespace std;


float GeoSum(int i,int k,float sum)
{
    if(i>k)
        return sum;

    sum += (1.0/(pow(2,i)));

    GeoSum(i+1,k,sum);
}

int main()
{
    cout<<"Enter the number of terms you want in the progression : ";
    int k;
    cin>>k;
    cout<<"The geometric sum is : "<<GeoSum(0,k,0);
    return 0;
}
