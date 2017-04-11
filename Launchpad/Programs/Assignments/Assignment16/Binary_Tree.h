#ifndef Binary_Tree_h
#define Binary_Tree_h
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

template<typename T>
class BTNode
{
    T data;
    BTNode *left,*right;
public:
    BTNode() : data(0),left(0),right(0)  {}
    BTNode(const T & el) : data(el),left(0),right(0)  {}
    template<typename U>
    friend class BinaryTree;
};

template<typename T>
class BinaryTree
{
    BTNode<T> * root;
public:
    BinaryTree() : root(0)  {}
    void create_Tree()
    {
        if(root!=NULL)
        {
            throw "The root already exists";
        }
        else
        {
            root = createTreeHelper();
        }
    }
private:
    static BTNode<T> * createTreeHelper()
    {
        T el;
        cout<<"Enter the data for the node : ";
        cin>>el;
        BTNode<T> * curr = new BTNode<T>(el);
        char ch;
        cout<<"Does "<<el<<" have left child (y/n) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            curr->left = createTreeHelper();
        }
        cout<<"Does "<<el<<" have right child (y/n) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            curr->right = createTreeHelper();
        }
        return curr;
    }

    static void printPreOrderHelper(const BTNode<T> * curr) {

        if(curr==0)
        {
            return ;
        }

        cout << curr->data << " ";
        printPreOrderHelper(curr->left);
        printPreOrderHelper(curr->right);

    }

public:
    void printPreOrder() const {
        printPreOrderHelper(root);
    }

private:
    static BTNode<T> * findLowestCommonAncestorHelper(const T & n1,const T & n2,BTNode<T> * curr)
    {
        if(curr==NULL)
        {
            return curr;
        }
        else if(curr->data == n1 || curr->data == n2)
        {
            return curr;
        }

        pair<BTNode<T> *,BTNode<T> * > p;
        p.first = findLowestCommonAncestorHelper(n1,n2,curr->left);
        p.first = findLowestCommonAncestorHelper(n1,n2,curr->left);
        if(p.first==NULL&&p.second!=NULL)
        {
            p.first = findLowestCommonAncestorHelper(n1,n2,curr->right);
        }
        else if(p.second==NULL&&p.first!=NULL)
        {
            p.second = findLowestCommonAncestorHelper(n1,n2,curr->right);
        }
        else if(p.first==NULL && p.second==NULL)
        {
            p.first = findLowestCommonAncestorHelper(n1,n2,curr->right);
            p.second = findLowestCommonAncestorHelper(n1,n2,curr->right);
        }


        if(p.first!=NULL && p.second!=NULL)
        {
            return curr;
        }
        else
        {
            return NULL;
        }
    }

public:
    const BTNode<T> * findLowestCommonAncestor(const T & n1,const T & n2)
    {
        BTNode<T> * node = findLowestCommonAncestorHelper(n1,n2,root);
        if(node!=NULL)
        {
            return node;
        }
        else
        {
            throw "One of the entered node is not present in the tree";
        }
    }

private:
    static calculateDiameterHelper()
    {

    }

public:
    int calculateDiameter() const
    {

    }

};
#endif // Binary_Tree_h
