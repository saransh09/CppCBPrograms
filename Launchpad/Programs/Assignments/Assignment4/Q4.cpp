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
    int a[11]={1,3,1,5,6,1,1,9,0,1,15};
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10-i;j++)
        {
            if(a[j]>=a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
    int b[6],i=0,j=0;
    while(a[i]!=a[i+1])
    {
        b[j++]=a[i++];
    }
    i+=5;
    while(j<6)
    {
        b[j++]=a[i++];
    }
    cout<<endl<<"The non repeated elements are : "<<endl;
    for(j=0;j<6;j++)
    {
        cout<<b[j]<<'\t';
    }
    return 0;
}
