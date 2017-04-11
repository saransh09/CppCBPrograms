#include<iostream>
#include"HeaderFiles/first.h"
#include"HeaderFiles/second.h"
using namespace std;
int main() {
    int arr[] = { 1,2,3,4,4,5};
    cout << sumofArray(arr, 6) << endl;
    reverseAndPrint(arr, 6);
    return 0;
}
