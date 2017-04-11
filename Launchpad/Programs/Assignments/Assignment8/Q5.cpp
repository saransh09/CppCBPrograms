#include<iostream>
#include<cmath>
using namespace std;

int Convert2Int(char *a,int s,int e,int num,int l)
{
    if(s>e)
        return num;

    num += (((int)a[s])-48) * pow(10,l--);

    Convert2Int(a,s+1,e,num,l);
}

int main()
{
    cout<<"Enter a number : ";
    char a[100];
    cin.getline(a,100);
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    cout<<Convert2Int(a,0,i-1,0,i-1);
    return 0;
}
