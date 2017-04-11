#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the number of rows desired : ";
    cin >> n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n-i)
        {
            cout << " ";
            j++;
        }
        int k=1;
        while(k<=(2*i)-1)
        {
            cout << k;
            k++;
        }
        i++;
        cout << '\n';
    }
    return 0;
}
