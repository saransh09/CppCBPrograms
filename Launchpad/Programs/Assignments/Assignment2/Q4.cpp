#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the year to check for Leap Year\n";
    int y;
    cin>>y;
    while(y%4==0)
    {
        if(y%100==0&&y%1000!=0)
        {
            cout<<"Not a leap year";
            return 0;
        }
        else
        {
            cout<<"Leap year";
            return 0;
        }
    }
    while(y%4!=0)
    {
        cout<<"Not leap year";
        return 0;
    }
}
