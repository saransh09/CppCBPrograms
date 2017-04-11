#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int temp;
    int a[8]={45,-8,6,25,-1,54,5,-9};
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
    for(int k=0;k<8;k++)
    {
        cout<<a[k]<<'\t';
    }
    return 0;
}
