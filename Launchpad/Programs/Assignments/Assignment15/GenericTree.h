#ifndef GENERIC_TREE_H
#define GENERIC_TREE_H
#include<stack>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

template<typename T>
class GTNode
{
    T data;
    vector<GTNode *> children;
public:
    GTNode()  {}
    GTNode(const T & el) : data(el) {}
    template<typename U>
    friend class GenericTree;
};

template<typename T>
class GenericTree
{
    GTNode<T> * root;

public:
    GenericTree() : root(0) {}

private:
    static GTNode<T> * createTreeHelper()
    {
        T el;
        cout<<"Enter the data for the node : ";
        cin>>el;
        GTNode<T> * currnode = new GTNode<T> (el);
        int child;
        cout<<"Enter the number of children for that node : ";
        cin>>child;
        for(int i=0;i<child;i++)
        {
            GTNode<T> * childaddress = createTreeHelper();
            currnode->children.push_back(childaddress);
        }
        return currnode;
    }

public:
    void createTree()
    {
        if(root!=NULL)
            throw "The tree is already created";

        root = createTreeHelper();
    }

private:
    static void printPreOrderHelper(const GTNode<T> * curr)
    {
        cout<<curr->data<<' ';
        for(int i=0;i<curr->children.size();i++)
        {
            printPreOrderHelper(curr->children[i]);
        }
    }

public:
    void printPreOrder()
    {
        if(root==NULL)
            return;

        printPreOrderHelper(root);
    }

private:
    static void clearHelper(GTNode<T> * curr)
    {
        for(int i=0;i<curr->children.size();i++)
        {
            clearHelper(curr->children[i]);
        }
        delete curr;
    }

public:
    void clear()
    {
        if(root==NULL)
            return;

        clearHelper(root);
    }

    ~GenericTree()
    {
        clear();
    }

private:
    static GTNode<T> * copyTreeHelper(const GTNode<T> * otheraddress)
    {
        GTNode<T> * curr = new GTNode<T> * (otheraddress->data);
        for(int i=0;i<otheraddress->children.size();i++)
        {
            GTNode<T> * childaddress = copyTreeHelper(otheraddress->children[i]);
            curr->children.push_back(childaddress);
        }
        return curr;
    }

public:
    GenericTree(const GenericTree & T1)
    {
        if(T1.root==NULL)
            return;

        root = copyTreeHelper(T1.root);
        return;
    }

    GenericTree & operator=(const GenericTree & T1)
    {
        clear();
        if(T1.root==NULL)
            return *this;

        root = copyTreeHelper(T1.root);
        return *this;
    }

    void createTreeLevelWise()
    {
        if(root)
        {
            throw "The tree already exists";
        }

        T el;
        int childcount;
        cout<<"Enter the data for the node : ";
        cin>>el;
        root = new GTNode<T> (el);
        queue<GTNode<T> *> Q;
        Q.push(root);
        while(!Q.empty())
        {
            GTNode<T> * curr = Q.front();
            Q.pop();
            cout<<"Enter number of children : ";
            cin>>childcount;
            for(int i=0;i<childcount;i++)
            {
                cout<<"Enter the data for the "<<i+1<<" child : ";
                cin>>el;
                GTNode<T> * childnode = new GTNode<T>(el);
                curr->children.push_back(childnode);
                Q.push(childnode);
            }
        }
    }

private:
    static const GTNode<T> * getLargestNodeHelper(GTNode<T> * curr)
    {
        GTNode<T> * largest = curr;
        for(int i=0;i<curr->children.size();i++)
        {
            GTNode<T> * childans = getLargestNodeHelper(curr->children[i]);
            if(childans->data>largest->data)
            {
                largest = childans;
            }
            return largest;
        }
    }

public:
    const T & getLargestNode() const
    {
        if(root==NULL)
            throw "The tree is empty";

        const GTNode<T> * largest = getLargestNodeHelper(root);
        return largest->data;
    }

    void printAllElementsAtDepthKUsingQueue(int k) const
    {
        if(root==NULL)
            throw "The tree is empty";

        queue<pair<GTNode<T> *,int> > Q;
        pair<GTNode<T> *,int> P(root,0);
        Q.push(P);
        while(!Q.empty())
        {
            pair<GTNode<T> *,int> temp = Q.front();
            Q.pop();
            if(temp.second==k)
            {
                cout<<temp.first->data<<' ';
                continue;
            }

            for(int i=0;i<P.first->children.size();i++)
            {
                pair<GTNode<T> *,int> childpair;
                childpair.first = temp.first->children[i];
                childpair.second = temp.second + 1;
                Q.push(childpair);
            }
        }
    }

private:
     static GTNode<T> * printAllElementsAtDepthKUsingRecursionHelper(GTNode<T> * curr,int k,int a)
    {
        if(k==0)
        {
            cout<<curr->data;
            return NULL;
        }
        for(int i=0;i<curr->children.size();i++)
        {
            GTNode<T> * childans = curr->children[i];
            if(a==k)
            {
                cout<<childans->data<<' ';
                continue;
            }
            printAllElementsAtDepthKUsingRecursionHelper(childans,k,a+1);
        }
    }

public:
    const void printAllElementsAtDepthKUsingRecursion()
    {
        if(root==NULL)
            throw "The tree is empty";

        cout<<"Enter the depth where the nodes are needed : ";
        int k;
        cin>>k;
        printAllElementsAtDepthKUsingRecursionHelper(root,k,1);
    }

         void printRootToEl(T & el)
    {
        //T el;
        //cout<<"Enter the element whose path is to be printed : ";
        //cin>>el;
        vector<GTNode<T> *> V;
        bool ans = printRootToElHelper(root,el,V);
        for(int i=V.size();i>=0;i--)
        {
            cout<<V[i]->data<<"-->";
        }
        if(ans==false)
        {
            cout<<"The entered elements was not found in the tree"<<endl;
        }
    }

private:
    static bool printRootToElHeper(GTNode<T> * curr,T & el,vector<GTNode<T> *> & V)
    {
        if(curr->data == el)
        {
            V.push_back(curr);
            return true;
        }

        for(int i=0;i<curr->children.size();i++)
        {
            bool  childans = printRootToElHelper(curr->children[i],el,V);
            if(childans==true)
            {
                V.push_back(curr->children[i]);
                return true;
            }
        }
        return false;
    }

    static int getHeightHelper(GTNode<T> * curr)
    {
        int Height = 0,a;
        if(curr==NULL)
            return 1;

        for(int i=0;i<curr->children.size();i++)
        {
            a = getHeightHelper(curr->children[i]);
            if(Height<a)
                Height = a;
        }
        return a;
    }

public:
    const void getHeight() const
    {
        cout<<"The height of the tree is : "<<getHeightHelper(root);
        return;
    }
};

#endif // GENERIC_TREE_H
