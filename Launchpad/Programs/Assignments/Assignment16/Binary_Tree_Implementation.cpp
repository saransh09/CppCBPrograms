#include "Binary_Tree.h"
#include<iostream>
using namespace std;

int main()
{
    BinaryTree<int> T;
    T.create_Tree();
    T.printPreOrder();
    T.findLowestCommonAncestor(5,8);

    return 0;
}

