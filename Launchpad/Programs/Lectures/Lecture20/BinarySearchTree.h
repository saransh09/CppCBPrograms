#ifndef Binary_Search_Tree_h
#define Binary_Search_Tree_h
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

template<typename T>
class BTNode {
    T data;
    BTNode * left;
    BTNode * right;
    public:
    BTNode() {}
    BTNode(const T & el) : data(el),left(0),right(0) {}

    template<typename U>
    friend class BinarySearchTree;
};
template<typename T>
class BinarySearchTree
{
    BTNode<T> * root;
    //BTNode<T> * maxel;
    //BTNode<T> * minel;
public:
    BinarySearchTree() : root(0)  {}
private:
    static void InsertElementHelper(BTNode<T> *  curr,const T & el)
    {
        if(curr->data>=el)
        {
            if(curr->left==NULL)
            {
                BTNode<T> * newNode = new BTNode<T>(el);
                curr->left = newNode;
                return;
            }
            InsertElementHelper(curr->left,el);
        }
        if(curr->data<el)
        {
            if(curr->right==NULL)
            {
                BTNode<T> * newNode = new BTNode<T>(el);
                curr->right = newNode;
                return;
            }
            InsertElementHelper(curr->right,el);
        }
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

    static BTNode<T> * findMinHelper(BTNode<T> * curr)
    {
        if(curr->left==NULL)
        {
            return curr;
        }
        findMinHelper(curr->left);
    }

    static BTNode<T> * findMaxHelper(BTNode<T> * curr)
    {
        if(curr->right==NULL)
        {
            return curr;
        }
        findMaxHelper(curr->right);
    }

    static BTNode<T> * findElementHelper(BTNode<T> * curr,T el)
    {
        if(curr==NULL)
        {
            return NULL;
        }

        if(curr->data==el)
        {
            return curr;
        }
        else if(curr->data>el)
        {
            return findElementHelper(curr->left,el);
        }
        else if(curr->data<el)
        {
            return findElementHelper(curr->right,el);
        }
    }
public:
    void InsertIterative(const T & el)
    {
        BTNode<T> * newNode = new BTNode<T>(el);
        if(root==NULL)
        {
            root = newNode;
            return;
        }
        BTNode<T> * it = root,*previt = NULL;
        while(it!=NULL)
        {
            previt = it;
            if(it->data<el)
            {
                it = it->right;
            }
            else
            {
                it = it->left;
            }
        }
        if(previt->data < el)
        {
            previt->right = newNode;
        }
        else
        {
            previt->left = newNode;
        }
    }
    void InsertElement(const T & el)
    {
        if(root==NULL)
        {
            BTNode<T> * newNode = new BTNode<T>(el);
            root = newNode;
            return;
        }

        InsertElementHelper(root,el);
    }
    void printPreOrder() const {
        printPreOrderHelper(root);
    }
    void findMin()
    {
        if(root==NULL)
        {
            throw "The tree is empty";
        }

        BTNode<T> * temp = findMinHelper(root);
        cout<<"The minimum element is : "<<temp->data;
    }
    void findMax()
    {
        if(root==NULL)
        {
            throw "The tree is empty";
        }

        BTNode<T> * temp = findMaxHelper(root);
        cout<<"The maximum element is : "<<temp->data;
    }
    bool findElement(T el)
    {
        if(root==NULL)
        {
            throw "The tree is empty";
        }

        BTNode<T> * temp = findElementHelper(root,el);

        if(temp==NULL)
            return false;
        else
            return true;
    }
private:
    /*BTNode<T> * GenerateTreeUsingPreOrderTraversalHelper(const vector<T> & V,int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }
        if(S==e)
        {
            BTNode<T> * temp = new BTNode<T>
        }
        BTNode<T> * temp = new BTNode<T>(V[s]);
        int i = s;
        while(V[i]<=V[s] && i<=e)
        {
            i++;
        }
        temp->left = GenerateTreeUsingPreOrderTraversalHelper(V,s+1,i);
        temp->right = GenerateTreeUsingPreOrderTraversalHelper(V,i+1,e);
        return temp;
    }*/
    BTNode<T> * GenerateTreeUsingPreOrderTraversalHelper(const vector<T> & V,int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }

        BTNode<T> * temp = new BTNode<T>(V[s]);
        int i = s;
        while(V[i]<=V[s] && i<=e)
        {
            i++;
        }
        temp->left = GenerateTreeUsingPreOrderTraversalHelper(V,s+1,i-1);
        temp->right = GenerateTreeUsingPreOrderTraversalHelper(V,i,e);
        return temp;
public:
    void GenerateTreeUsingPreOrderTraversal(vector<T> & V,int n)
    {
        if(root)
            throw "The tree is not empty";

       root =  GenerateTreeUsingPreOrderTraversalHelper(V,0,n-1);
    }

private:
    static void CheckWhetherBSTorNotHelper(const BTNode<T> * curr,T max,T min)
    {
        if(curr->data>max || )
            max=curr->data;

        if(curr->data<min)
            min=curr->data;

        CheckWhetherBSTorNotHelper(curr->left);
        if(max>curr->data)
        {

        }

        return(CheckWhetherBSTorNotHelper(root->left,min,root->data) && CheckWhetherBSTorNotHelper(root->right,root->data,max));
    }

private:
    static void PrintInorderIterativeHelper(const BTNode<T> * curr)
    {
        stach<T> S;
        BTNode<T> * temp = curr;
        S.push(curr);
        while(!S.empty())
        {
            while(temp!=NULL)
            {
                S.push(temp->left);
                temp = temp->left;
            }

            if(S.top()->right==NULL)
            {
                cout<<S.top()->data;
                S.pop();
                curr=S.top();
            }
            else
            {
                BTNode<T> * t = S.top()->right;
                cout<<S.top()->data;
                S.pop();
                S.push(t);
                curr=S.top();
            }
        }
    }

public:
    const void PrintInorderIterative(const BTNode<T> * curr) const
    {
        PrintInorderIterativeHelper(root);
    }
};
#endif // Binary_Search_Tree_h
