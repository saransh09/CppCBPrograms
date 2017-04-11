#include<iostream>
using namespace std;
void fun(int *p) {
    p = new int;
    *p = 6;
}
int main() {
    int * p;
    fun(p);
    cout << *p << endl;
    return 0;
}
