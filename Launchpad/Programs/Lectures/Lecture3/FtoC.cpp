#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the initial , final and step values respectively\n";
    int i,f,s;
    cin>>i>>f>>s;
    if(s<f-i)
    {
        int a = i;
        while(a<=f)
        {
            cout<<a<<'\t'<<(int)((5.0/9)*(a-32))<<'\n';
            a+=s;
        }
    }
    else
    {
        cout<<"Step value should be less than the difference of initial and final values";
    }

    return 0;
}
