#include<iostream>
#include"GenericTree.h"
using namespace std;

int main()
{
    GenericTree<char> T;
    //T.createTree();
    T.createTreeLevelWise();
    //T.printRouteToEl()
    T.printPreorder();
    T.getSecondLargest();
    return 0;
}
