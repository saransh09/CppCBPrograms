#include<iostream>
#include"practice_generic.h"
using namespace std;
int main() {
    GenericTree<int> T;
    T.createTree();
    cout<<printPreOrder();
    

    return 0;
}
