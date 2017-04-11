#include<iostream>
using namespace std;
void fun(int & x) {
    x = 100;
}
void fun(int x ) {
    x = 100;
}
int main() {
    int y = 10;
    fun(y);
    cout << y << endl;
    return 0;
}
