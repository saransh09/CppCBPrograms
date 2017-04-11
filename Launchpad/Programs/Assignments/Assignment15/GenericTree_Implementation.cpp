#include "GenericTree.h"
#include<iostream>
using namespace std;

int main()
{
    GenericTree<char> T;
    T.createTree();
    T.printPreOrder();
    //T.printAllElementsAtDepthKUsingRecursion();
    //printRootToEl();
    T.getLargestNode();
    return 0;
}

