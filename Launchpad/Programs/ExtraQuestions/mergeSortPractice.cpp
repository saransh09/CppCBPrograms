#include <iostream>
using namespace std;

// int length(int * array){
// 	return sizeof(array)/sizeof(array[0]) - 1;
// }


void merge(int *arr, int start, int end) {
    int mid = (start+end)/2;
    int k = 0, i = start, j = mid+1;
    int temp[1000000];
    while(i <=mid && j <=end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++; k++;
        } else {
            temp[k] = arr[j];
            j++; k++;
        }
    }
    while (i <=mid) {
        temp[k] = arr[i];
        k++;i++;
    }
    while (j <= end) {
        temp[k] = arr[j];
        k++; j++;
    }
    for (int k = start; k <= end; k++) {
        arr[k] = temp[k-start];
    }
}
void mergesort(int *arr, int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start+end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, end);

}

int main(){
	int arr[10] = {3,10,53,-12,24,551,-123,0,1,-9};
	// for (int i = 0; i < 9; i++)
	// {
	// 	cout<<arr[i];
	// }
	mergesort(arr,0,10);
	for(int z;z<10;z++){
		cout<<arr[z]<<' ';
	}
	return 0;
}
