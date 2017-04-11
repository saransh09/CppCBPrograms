#include<iostream>
using namespace std;



void Swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

void rev(int* a,int s,int e)
{
    if(s>=e)
        return;

    Swap(a+s,a+e);
    rev(a,s+1,e-1);
}

int main()
{
    int a[5] = {1,2,3,4,9};
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;

    rev(a,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}
