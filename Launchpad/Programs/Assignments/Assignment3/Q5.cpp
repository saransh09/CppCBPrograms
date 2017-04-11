#include<iostream>
#include<time.h>
using namespace std;

int main()
{
    cout<<"Enter the base of the triangle\n";
    long long int x;
    clock_t t1,t2;
    t1 = clock();
    cin>>x;
    if(x==1||x==2||x==3)
    {
        cout<<"The number of triangles possible are : 0";
    }
    else
    {
        cout<<"The number of triangles possible are : "<<(((x/2)*(x/2))-(x/2))/2<<endl;
    }
    t2 = clock();
    cout<<t2-t1;
    return 0;
}
