#include<iostream>
using namespace std;
void MergeTwoSortedArraysIntoThird(int * A, int N, int *B, int M, int *C) {
    if (N == 0 && M == 0) {
        return;
    }
    if ( N == 0 ||( M > 0 && *A > *B)) {
        *C = *B;
        MergeTwoSortedArraysIntoThird(A, N, B+1, M-1, C+1);
    } else {
        *C = *A;
        MergeTwoSortedArraysIntoThird(A+1, N-1, B, M, C+1);
    }
    return;
}
void merge(int *arr, int N) {
    int C[100];
    int *A = arr;
    int *B = arr+N/2;
    MergeTwoSortedArraysIntoThird(A,N/2,B,N-N/2,C);
    for (int i = 0; i < N; i++) {
        arr[i] = C[i];
    }
    return;
}
void MergeSort(int *arr, int N) {
    if (N == 1 || N == 0) {
        return;
    }
    int *leftarr = arr;
    int *rightarr = arr + N/2;
    MergeSort(leftarr, N/2);
    MergeSort(rightarr, N - N/2);
    merge(arr, N);
    return;
}

int main() {
    int arr[100];
    int N; 
    cin >> N; 
    for (int i = 0; i < N ; i++) {
        cin >> arr[i];
    }
    MergeSort(arr, N);
    cout << "Array after sorting" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
