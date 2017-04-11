#ifndef SECOND_H
#define SECOND_H
#include "first.h"
void reverse(int *arr, int N) {
    if (N == 0) {
        return;
    }
    int temp = *arr;
    *arr = *(arr+N-1);
    *(arr+N-1) = temp;
    reverse(arr+1, N-2);
    return;
}
void reverseAndPrint(int * arr, int N) {
    reverse(arr, N);
    printArray(arr, N);
}
#endif
