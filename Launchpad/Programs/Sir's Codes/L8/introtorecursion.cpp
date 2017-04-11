#include<iostream>
using namespace std;
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    // return n * factorial(n-1);
    int ans = factorial(n-1);
    ans = n * ans;
    return ans;
}
int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    int ans = gcd(b, a % b);
    return ans;
}
void printArrayVersion1(int *arr, int N) {
    if (N == 0) {
        return;
    }
    cout << *arr <<  " "; // cout << arr[0] << " ";
    printArrayVersion1(arr+1, N-1);
    return;
}
int binarySearch(int *arr, int startindex, int endindex, int value) {
    if (startindex > endindex) {
        return -1;
    }
    int mid = (startindex+endindex)/2;
    if (arr[mid] == value) {
        return mid;
    }else if (arr[mid] > value) {
        return binarySearch(arr, startindex, mid-1, value);
    } else {
       return binarySearch(arr, mid+1, endindex, value);
    }
}
int binarySearch(int *arr, int N, int value) {
    if (N == 0) {
        return - 1;
    }
    int mid = N/2;
    if (arr[mid] == value) {
        return mid;
    } else if (arr[mid] > value) {
        int index = binarySearch(arr, mid, value);
        return index;
    } else {
        int index = binarySearch(arr+mid+1, N-mid-1, value);
        if (index != -1) {
            index += mid+1;
        }
        return index;
    }
}

int largestOfArray(int *arr, int N) {
    if (N == 1) {
        return *arr;
    }
    int subans = largestOfArray(arr+1, N-1);
    if (subans > *arr) {
        return subans;
    } else {
        return *arr;
    }

}

void printArrayVersion2(int *arr, int index, int N) {
    if (index == N) {
        return;
    }
    cout << arr[index] << " ";
    printArrayVersion2(arr, index+1, N);
    return;
}


int main() {
    int ans = factorial(5);
    int arr[] = { 1, 2, 4, 6, 8 , 12, 19};
    int index = binarySearch(arr, 7, 3);
    cout << index << endl;
    return 0;
}
