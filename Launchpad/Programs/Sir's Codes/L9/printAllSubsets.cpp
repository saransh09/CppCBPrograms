#include<iostream>
using namespace std;
void printAllSubsets(int *arr, int N, int *sol, int size) {
    if (N == 0) {
        for (int i =0 ; i < size; i++) {
            cout << sol[i] << ' ';
        }
        cout << endl;
        return;
    }
/*    int sol1[100], sol2[100];
    for (int i = 0; i <size; i++) {
        sol1[i] = sol[i];
        sol2[i] = sol[i];
    }*/
    printAllSubsets(arr+1, N-1, sol, size);
    sol[size] = *arr;
    printAllSubsets(arr+1, N-1, sol, size+1);
    return;
}
int main() {
    int arr[] = { 1,2,3,4};
    int sol[100];
    printAllSubsets(arr, 4, sol, 0);
    return 0;
}
