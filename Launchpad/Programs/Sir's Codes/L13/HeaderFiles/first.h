#ifndef FIRST_H
#define FIRST_H
#include<iostream>
using namespace std;
int sumofArray(int *arr, int N) {
    if (N == 0) {
        return 0;
    }
    return *arr + sumofArray(arr+1, N-1);
}
void printArray(int * arr, int N) {
    for (int i = 0; i < N ; i++) {
        cout << arr[i] <<  " ";
    }
    cout << endl;
}
#endif
