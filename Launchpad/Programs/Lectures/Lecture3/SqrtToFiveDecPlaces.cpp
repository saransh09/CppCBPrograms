#include<iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the Number for which Square Root is to be computed";
    cin>>num;
    int i = 1;
    while(i*i<=num)
    {
        i+=1;
    }
    float ans = i-1;
    float f = 0.1;
    float temp;
    int k=1,p,d;
    while(k<=5)
    {
        p=1;
        temp = ans + f*p;
        while(p<=9 && temp*temp <= num)
        {
            p+=1;
            temp = ans + f*p;
        }
        d = p-1;
        ans = ans + f*d;
        f = f/10;
        k+=1;
    }

    cout<<" Ans is : " << ans << endl;
    return 0;
}
