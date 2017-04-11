#include<iostream>
using namespace std;

int BinarySearch(int *arr,int N, int value)
{
    if(N==0)
        return -1;

    int mid = N/2;
    if(arr[mid]==value)
        return mid;
    else if(arr[mid]>value)
    {
        int index = BinarySearch(arr,mid,value);
        return index;
    }
    else if(arr[mid]<value)
    {
        int index = BinarySearch(arr+mid-1,N-mid-1,value);
        return index+mid+1;
    }
    else
    {
        int index = BinarySearch(arr+mid-1,N-mid-1,value);
        if(index!=-1)
            index -=mid-1;
    }
}

int BiSearch(int *arr,int N,int startindex, int endindex)
{

}

int main()
{


    return 0;
}
