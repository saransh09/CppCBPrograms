#include "Generic_Tree_1.h"
#include<iostream>
using namespace std;

int main()
{
    GenericTree<int> T;
    T.createTree();
    T.printPreOrder();
    cout<<endl;
   /* V.createTree();
    V.printPreOrder();*/
    //cout<<T.getHeight();
    //cout<<endl<<T.countLeafNodes();
    //cout<<endl<<"The number of nodes with data greater than the root node are : "<<T.countNodesWithDataGreaterThanRoot();
    cout<<endl;
    /*if(T==V)
    {
        cout<<"The trees are identical";
    }
    else
        cout<<"the trees are not identical";*/
    T.findSpecialNode();


    return 0;
}


