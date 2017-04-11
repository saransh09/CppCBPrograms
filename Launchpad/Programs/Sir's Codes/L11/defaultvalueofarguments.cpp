#include<iostream>
using namespace std;
int product(int a, int b = 10) {
    return a * b;
}
int a = 10;
int main() {
    cout << product() << endl;
    cout << product(,5) << endl; // Invlid
    cout << product(5) << endl;
    cout << product(10, 20) << endl;
    return 0;
}
