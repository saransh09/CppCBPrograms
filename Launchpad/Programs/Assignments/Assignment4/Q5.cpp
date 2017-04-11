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
    cout<<"Enter 10 numbers for the first array"<<endl;
    int a[10];
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }

    cout<<"Enter 10 numbers for the second array"<<endl;
    int b[10];
    for(int i=0;i<10;i++)
    {
        cin>>b[i];
    }

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9-i;j++)
        {
            if(b[j]>b[j+1])
            {
                swap(&b[j],&b[j+1]);
            }
        }
    }



    return 0;
}
