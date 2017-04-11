#include<iostream>
using namespace std;
void func() {
    static int x;
    x = 10;
    x++;
    cout << x << endl;
    return;
}
int main() {
    func();
    func();
    func();
    return 0;
}
