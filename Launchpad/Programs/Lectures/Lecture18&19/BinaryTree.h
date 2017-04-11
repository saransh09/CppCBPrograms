#ifndef BinaryTree_h
#define BinaryTree_h
#include<iostream>
#include<queue>
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
    friend class BinaryTree;
};

template<typename T>
class BinaryTree {
    BTNode<T> * root;
    public:
    BinaryTree() : root(0) {}
    void createTree() {
        if (root!= NULL) {
            throw "Tree already exist";
        }
        root = createTreeHelper();
    }
    private:
    static BTNode<T> * createTreeHelper() {
        T el;
        cout << "Enter data for node ";
        cin >> el;
        BTNode<T> * curr = new BTNode<T>(el);
        char ch;
        cout<<"Does "<<el<<" have left tree";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            curr->left = createTreeHelper();
        }
        cout<<"Does "<<el<<" have right tree";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            curr->right = createTreeHelper();
        }
        return curr;
    }
    public:

    BinaryTree(vector<T> & in,vector<T> & pre)
    {

    }

    void printPreOrder() const {
        printPreOrderHelper(root);
    }
    private:
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
    ~BinaryTree() {
        clear();
    }
    void clear() {
        clearHelper(root);
        root = NULL;
    }
    private:
    static void clearHelper(BTNode<T> * curr) {
        if(curr==0)
        {
            return;
        }
        clearHelper(curr->left);
        clearHelper(curr->right);
        delete curr;
    }
    public:

    void mirror()
    {
        if(root==0)
            return;

        mirrorHelper(root);
    }

    private:


    void mirrorHelper(BTNode<T> * curr)
    {
        if(curr==NULL)
            return;

        mirrorHelper(curr->left);
        mirrorHelper(curr->right);


        BTNode<T> * temp;
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
    }

    private:

    BTNode<T> * deleteHalfNodes(BTNode<T> * curr)
    {
        if(curr==NULL)
            return NULL;


        if(curr->left==NULL && curr->right!=NULL)
        {
            BTNode<T> * temp = deleteHalfNodes(curr->right);
            delete curr;
            return temp;
        }
        else if(curr->left!=NULL && curr->right==NULL)
        {
            BTNode<T> * temp = deleteHalfNodes(curr->left);
            delete curr;
            return temp;
        }
        curr->left = deleteHalfNodes(curr->left);
        curr->right = deleteHalfNodes(curr->right);
        return curr;
    }

    public:

        void deleteHalf()
        {
            if(root==NULL)
                return;

            root = deleteHalfNodes(root);
        }

     /*   void printPostOrderRec()
        {
            if(root==NULL)
                return;

            stack<pair<BTNode<T> *,int> > S(0,0);

        }*/

    private:
        static int minInsetionRequired(const BTNode<T> * r1,const BTNode<T> * r2)
        {
            int c=0;
            if(r1==NULL)
            {
                return IncrementerHelper(r2);
            }

            BTNode<T> * curr1 = r1;
            BTNode<T> * curr2 = r2;

            if((curr1->left!=NULL && curr2->left==NULL) || (curr1->right!=NULL && curr2->right==NULL))
            {
                return -1;
            }

            if((curr1->left==NULL && curr2->left==NULL) || (curr1->right==NULL && curr2->right==NULL))
            {
                return 0;
            }

            if((curr2->left!=NULL && curr1->left==NULL) || (curr2->right!=NULL && curr1->right==NULL))
            {
                return 1;
            }

            int a,b;

            if(c!=-1)
                    {
                        if(a==-1)
                        {
                            c=-1;
                        }
                        else if(a==1)
                        {
                            c++;
                        }
                    }

            f(c!=-1)
                    {
                        if(b==-1)
                        {
                            c=-1;
                        }
                        else if(b==1)
                        {
                            c++;
                        }
                    }

            a = minInsetionRequired(r1->left,r2->left);

            b = minInsetionRequired(r1->right,r2->right);

            return c;
        }

        static int IncrementerHelper(const BTNode<T> * r1)
        {
            if(r1==NULL)
            {
                return 0;
            }

            return IncrementerHelper(r1->left) + IncrementerHelper(r1->right) + 1;
        }
    private:


};




#endif // BinaryTree_h
