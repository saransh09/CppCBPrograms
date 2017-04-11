#include<iostream>
using namespace std;


int main()
{
    int a[8]={-9,1,45};
    int b[5]={2,12,47,197,998};
    int i=2,j=4;
    for(int k=7;k<0;k--)
    {

        while(i>0 && j>0)
        {
            if(a[i]>b[j])
            {
                a[k] = a[i--];
            }
        else
            {
                a[k] = b[j--];
            }
        }
    if(i<0)
    {
        a[k] = b[j--];
    }

    if(i<0)
    {
        a[k] = a[i--];
    }

    }
    for(int k=0;k<7;k++)
    {
        cout<<a[k]<<'\t';
    }
    cout<<endl;
    return 0;
}
