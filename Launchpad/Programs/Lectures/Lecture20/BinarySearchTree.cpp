#include "BinarySearchTree.h"
#include<iostream>
#include<vector>
//using namespace std;

int main()
{
    BinarySearchTree<int> T,T1;
    /*T.InsertElement(1);
    T.InsertElement(2);
    T.InsertElement(3);
    T.InsertElement(4);
    T.printPreOrder();
    cout<<endl;
    T.findMin();
    cout<<endl;
    T.findMax();
    if(T.findElement(1))
        cout<<endl<<"YES";
    else
        cout<<endl<<"NO";*/

    cout<<endl<<"Enter the number of elements : ";
    int n;
    cin>>n;
    vector<int> V;
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        V.push_back(a);
    }
    T1.GenerateTreeUsingPreOrderTraversal(V,n);
    T1.printPreOrder();

    return 0;
}


