#include<iostream>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

void Bubble(int *a,int e)
{
    if(e==0)
        return;

    int i=1;
    while(i<e)
    {
        if(a[i-1]>a[i])
            Swap(&a[i-1],&a[i]);

        i++;
    }

    Bubble(a,e-1);
}

int main()
{

    int a[8] = {1,9,5,6,4,11,7,14};
    Bubble(a,8);
    cout<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}
