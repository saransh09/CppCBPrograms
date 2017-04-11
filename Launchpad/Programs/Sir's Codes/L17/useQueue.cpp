#include<iostream>
#include"QueueAsDynamicArray.h"
using namespace std;
int main() {
    Queue<int> Q;
    for (int i =0; i < 10; i++) {
        Q.enqueue(i);
    }
    Queue<int> Q2 = Q;
    Q.clear();
    Q = Q2;
    while (!Q2.empty()) {
        cout << Q2.front() << " ";
        Q2.dequeue();
    }
    cout << endl;
    while(!Q.empty()) {
        cout << Q.front() << " ";
        Q.dequeue();
    }
    return 0;
}
