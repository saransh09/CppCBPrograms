#include<iostream>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
long getTimeinMicroSeconds() {
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}
int main() {
    int arr[1000000];
    int N;
    int i = 0,j;
    int pos, temp;
    cout << "Enter total numbers ( < 100) ";
    cin >> N;
    for (i = 0; i < N; i++) {
        arr[i] = N-i;
    }
    long starttime, endtime;
    starttime = getTimeinMicroSeconds();
    for (i = 0; i < N-1; i++) {
        pos = i;
        j = i+1;
        while (j <= N-1) {
            if (arr[j] < arr[pos]) {
                pos = j;
            }
            j = j+1;
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
    endtime = getTimeinMicroSeconds();
    cout << "Time Taken: " << endtime-starttime << endl;
/*    cout << "Array after sorting " << endl;
    for (i = 0; i < N; i++) {
        cout << arr[i] <<  " ";
    }
    cout << endl;*/
    return 0;
}
