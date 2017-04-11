#include<iostream>
using namespace std;
int * fun() {
    static int x = 10;
    cout << x << endl;
    return &x;
}
int & fun2() {
    static int y = 10;
    return y;
}
int & fun3(int x) {
    cout << &x << endl;
    x++;
    cout << x << endl;
    return x;
}
int & fun4() {
    int * ptr = new int;
    return *ptr;
}
int * fun5() {
    int * ptr = new int;
    return ptr;
}
int main() {
    int z = 10;
    cout << &z << endl;
    int & r = fun3(z);
    cout << &r << endl;
    r++;
    cout << z << endl;

/*  //  int * ptr = fun();
   // ptr = 23;
    int a = fun2();
    a++;
    int & t = fun2();
    t++;
    cout << t << endl;
    cout << a << endl;
//    fun();*/
    return 0;
}
