#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float a,b,c,x1,x2;
    cout<<"Enter the coefficient of x^2, x & constant respectively"<<endl;
    cin>>a>>b>>c;
    if(b*b - 4*a*c > 0)
    {
        x1 = ((-b)-sqrt(b*b - 4*a*c))/(2*a);
        x2 = ((-b)+sqrt(b*b - 4*a*c))/(2*a);
        cout<<"The roots are real and distinct"<<endl;
        cout<<"The roots are \t"<<x1<<'\t'<<x2<<endl;
    }
    else if(b*b - 4*a*c == 0)
    {
        x1 = (-b)/(2*a);
        x2 = (-b)/(2*a);
        cout<<"The roots are real and identical"<<endl;
        cout<<"The roots are \t"<<x1<<'\t'<<x2<<endl;
    }
    else if(b*b - 4*a*c < 0)
    {
        x1 = (sqrt(abs(b*b - 4*a*c))/(2*a));
        x2 = (-b)/(2*a);
        cout<<"The roots are imaginary"<<endl;
        cout<<"The roots are \t"<<x2<<"-"<<"i"<<x1<<'\t'<<x2<<"+"<<"i"<<x1<<endl;
    }



    return 0;
}
