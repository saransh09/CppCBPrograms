#include<iostream>
using namespace std;
void reverse(int *arr, int N) {
    for(int i = 0, j = N-1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
void reverse(char * str) {
    int len = strlen(str);
    for (int i = 0, j = len -1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
int reverse(int N) {
    int rev = 0;
    while (N > 0) {
        rev = rev * 10 + N%10;
        N = N/10;
    }
    return rev;
}
int reverse(float N) {
    return N;
}
int main() {
    int arr[] = { 1,2,3,4,4,5};
    char str[] = "Hello!";
    reverse(arr, 6);
    reverse(str);
    reverse(100);
    reverse(5.3);
}









