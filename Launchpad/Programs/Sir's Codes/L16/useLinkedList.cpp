#include<iostream>
#include"LL.h"
using namespace std;
int main() {
    LinkedList L1, L2;
 //   cout << L1.getStaicDataMember() << endl;
  //  cout << LinkedList::getStaicDataMember() << endl;
//    cout << L2.staticdatamember << endl;
    int N, val;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> val;
        L1.insertAtEnd(val);
    }
    L1.reversePrint();
/*
    try {
        (L1++).printList();
        (++L1).printList();
        L1[15] = 2;
        L1[3] = 5;
        L1.printList();
    }catch ( int val ) {
        cout << val << endl;
    } catch (const char * msg) {
        cout << msg << endl;
    }

    cout << "Anushray Gupta" << endl;*/
    /*
    LinkedList L2 = L1;
    L2.deleteFromHead();
    L2.deleteFromHead();
    L2 = L1;
    L2.deleteFromHead();
    L2.printList();
    L1.printList();*/

/*    cout << "Address of L " << &L << endl;
    LinkedList L2 = L;
    cout << "Address of L2 " << &L2 << endl;
    L2.deleteFromHead();
    LinkedList L3 = L + L2;
    cout << "Address of L3 " << &L3 << endl;
    L.printList();
    L2.printList();
    L3.printList();*/


/*    const LinkedList & L2 = L;
    L2.printList();
    L2.deleteFromHead();
//    LinkedList L2(L);
    L.deleteFromHead();
    L.deleteFromHead();
    L.printList();
    L2.printList();*/

    return 0;
}
