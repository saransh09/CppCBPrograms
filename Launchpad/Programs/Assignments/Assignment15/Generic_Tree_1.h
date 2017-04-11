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

private:
    static int getHeightHelper(GTNode<T> * curr,int & h,int & b)
    {
        if(curr!=NULL)
        {
            return 0;
        }
        for(int i=0;i<curr->children.size();i++)
        {
            GTNode<T> * childans = curr->children[i];
            int a  = getHeightHelper(childans,h);
            if(a>h)
                h = a;
        }
        return 0;
    }

public:
    int getHeight() const
    {
        int b=0;
        getHeightHelper(root,b);
        return b+1;
    }

private:
    static void countLeafNodesHelper(GTNode<T> * curr,int & b)
    {
        if(curr->children.size()==0)
            return 1;

        for(int i=0;i<curr->children.size();i++)
        {
            GTNode<T> * child = curr->children[i];
            int a = countLeafNodesHelper(child,b);
            if(a==1)
                {
                    b++;
                    continue;
                }
        }
        // return b;
    }

public:
    int countLeafNodes() const
    {
        if(!root)
        {
            throw "The tree is empty";
        }

        int b=0;
        countLeafNodesHelper(root,b);
        return b;
    }

private:
    static void countNodesWithDataGreaterThanRootHelper(GTNode<T> * curr,const T & d,int & b)
    {
        if(curr->data>d)
        {
            b++;
        }

        for(int i=0;i<curr->children.size();i++)
        {
            GTNode<T> * child = curr->children[i];
            countNodesWithDataGreaterThanRootHelper(child,d,b);
        }
    }
public:
    int countNodesWithDataGreaterThanRoot() const
    {
        if(!root)
        {
            throw "The tree is empty";
        }
        int b=0;
        countNodesWithDataGreaterThanRootHelper(root,root->data,b);
        return b;
    }

private:
    static pair<GTNode<T> * , GTNode<T> *> findSecondLargestNodeHelper(GTNode<T> * curr)
    {
        pair<GTNode<T> * , GTNode<T> *> ans(curr,0),childans;
        for(int i=0;i<curr->children.size();i++)
        {
            childans = findSecondLargestNodeHelper(curr->children[i]);
            if(childans.first->data > ans.first->data)
            {
                if(childans.second==NULL || ans.first->data > childans.second->data)
                {
                    ans.second = ans.first;
                }
                else
                {
                    ans.second = childans.second;
                }
                ans.first = childans.first;
            }
            else
                {
                    if(ans.second==NULL || ans.second->data < childans.first->data)
                    {
                        ans.second = childans.first;
                    }
                }
        }
        return ans;
    }

public:
    const GTNode<T> * findSecondLargestNode() const
    {
        if(root==NULL)
        {
            throw "The tree is empty";
        }

        pair<GTNode<T> * , GTNode<T> *> P = findSecondLargestNodeHelper(root);
        return P.second;
    }

    bool operator==(const GenericTree & U) const
    {
        if(root==NULL || U.root==NULL)
        {
            throw "One of the tree is empty";
        }
        bool b = true;
        return treeEqualityHelper(root,U.root,b);
    }

private:
    static bool treeEqualityHelper(GTNode<T> * curr,GTNode<T> * othercurr,bool b)
    {
        if(curr->data!=othercurr->data || curr->children.size()!=othercurr->children.size())
        {
            return false;
        }

        for(int i=0;i<curr->children.size();i++)
        {
            b = treeEqualityHelper(curr->children[i],othercurr->children[i],b);
            if(b==false)
            {
                break;
            }
        }
        return b;
    }

    static GTNode<T> * findSpecialNodeHelper(GTNode<T> * curr)
    {
        pair<GTNode<T> *,T> P(curr,curr->data);

        for(int i=0;i<curr->children.size();i++)
        {
            GTNode<T> * childans = findSpecialNodeHelper(curr->children[i]);
            if(childans->children.size()==0)
            {
                if(childans->data>P.second)
                {
                    P.first = childans;
                    P.second = childans->data;
                }
            }
            else
            {
                T d = childans->data;
                for(int i=0;i<childans->children.size();i++)
                {
                    d += childans->children[i]->data;
                }
                if(d>P.second)
                {
                    P.first = childans;
                    P.second = d;
                }
            }
        }
        return P.first;
    }

public:
    const GTNode<T> * findSpecialNode() const
    {
        if(root==NULL)
        {
            throw "The tree is empty";
        }
        GTNode<T> * test = findSpecialNodeHelper(root);
        cout<<test->data;
    }

private:
    static const GTNode<T> * justHigherThanKHelper(GTNode<T> * curr,int k)
    {

    }


private:
//     static void GTNode<T> * printZigZagHelper(GTNode<T> * curr)
//     {

//     }
};

#endif // GENERIC_TREE_H
