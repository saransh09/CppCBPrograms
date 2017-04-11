#include<iostream>
#include"LL.h"
using namespace std;
int main() {
    LinkedList<int> L1;
    LinkedList<char> L2;
    L1.insertAtEnd(1);
    L1.insertAtEnd(2);
    L1+=3;
    L2+=65;
    L2+=66;
    L1++;
    cout << L1 << endl;
    L2++;
    cout << L2 << endl;
    return 0;
}
