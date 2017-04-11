#ifndef GENERIC_TREE_H
#define GENERIC_TREE_H
#include<vector>
#include<Queue>
#include<iostream>
using namespace std;

template<typename T>

class GTNode
{
    T data;
    vector<GTNode *> children;

public:
    GTNode(){}                      //default constructor of the vector class is called itself...
    GTNode(const T & el) : data(el) {}          //No need to call the zero parameter constructor for the vector class...
    template<typename U>
    friend class GenericTree;
};

template<typename T>
class GenericTree
{
    GTNode<T> * root;

public:
    GenericTree() : root(0){}                           //We need a copy constructor, destructor,assignment operator

    void createTree()
    {
        if(root!=NULL)
        {
            throw "Tree Already Exists";
        }
        root = createTreeHelper();
    }

    void printPreorder() const
    {
        printPreorderHelper(root);
    }

    void clear()
    {
        clearHelper(root);
        root = NULL;
    }

    ~GenericTree()
    {
        clear();
    }

    GenericTree(const GenericTree & T1)
    {
        if(T1.root == NULL)
        {
            return;
        }
        root = copyTreeHelper(T1.root);
        return;
    }

    GenericTree & operator=(const GenericTree & T1)
    {
        clear();
        if(T1.root==NULL)
        {
            return *this;
        }
        root = copyTreeHelper(T1.root);
        return *this;
    }

private:
    static GTNode<T> * createTreeHelper()
    {
        T el;
        cout<<"Enter the data for the node : ";
        cin>>el;
        GTNode<T> * currnode = new GTNode<T>(el);
        int child;
        cout<<"Enter the number of children : ";
        cin>>child;
        for(int i=0;i<child;i++)
        {
            GTNode<T> * childaddress = createTreeHelper();
            currnode->children.push_back(childaddress);
        }
        return currnode;
    }

    static void printPreorderHelper(const GTNode<T> * curr)
    {
        cout<<curr->data<<' ';
        for(int i=0;i<curr->children.size();i++)
        {
            printPreorderHelper(curr->children[i]);
        }
    }

    static void clearHelper(GTNode<T> * curr)
    {
        for(int i=0;i<curr->children.size();i++)
        {
            clearHelper(curr->children[i]);
        }
        delete curr;
    }

    static GTNode<T> * copyTreeHelper(const GTNode<T> * otheraddress)
    {
        GTNode<T> *curr = new GTNode<T> * (otheraddress->data);
        for(int i=0;i<otheraddress.children.size();i++)
        {
            GTNode<T> * childaddress = copyTreeHelper(otheraddress[i]);
            curr->children.push_back(childaddress);
        }
        return curr;
    }
public :
    void createTreeLevelWise()
    {
        if(root)
        {
            throw "Tree already Exists";
        }

        T el;
        cout<<"Enter the data for the node : ";
        cin>>el;
        GTNode<T> * currnode = new GTNode<T>(el);
        int child;
        cout<<"Enter the number of children : ";
        cin>>child;
        root=currnode;
        if(child==0)
        {
            return;
        }
        queue<GTNode<T> *> Q;
        for(int i=0;i<child;i++)
        {
            cout<<"Enter the data for the child :";
            T e;
            cin>>e;
            GTNode<T> * ca = new GTNode<T> (e);
            currnode->children.push_back(ca);
            Q.push(ca);
        }
        while(!Q.empty())
        {
            GTNode<T> * temp = Q.front();
            cout<<"Enter the number of children : ";
            int n;
            cin>>n;
            if(n==0)
            {
                Q.pop();
                if(Q.empty())
                {
                    break;
                }
                continue;
            }
            for(int i=0;i<n;i++)
        {
            cout<<"Enter the data for the child :";
            T e;
            cin>>e;
            GTNode<T> * ca = new GTNode<T> (e);
            temp->children.push_back(ca);
            Q.push(ca);
        }
        Q.pop();

        }
    }

private:

/*    static const GTNode<T> * getLargestDataHelper(const GTNode<T> * curr) const
    {
        const GTNode<T> * largest = curr;
        for(int i=0;i<curr->children.size();i++)
        {
            const GTNode<T> * childans = getLargestDataHelper(curr->children[i]);
            if(largest->data < childans->data)
            {
                largest = childans;
            }
            return childans;
        }

    }

public:

    T getLargestData() const
    {
        if(root==NULL)
        {
            throw "Tree Is Empty";
        }
        const GTNode * largest = getLargestDataHelper(root);
        return largest->data;
    }
*/
    void printAllElementsAtDepthK(int K) const
    {
        if(root==NULL)
        {
            return;
        }
        queue<pair<GTNode<T>*,int> > Q;     //> > space between the brackets else left shift ambiguity arises "
        pair<GTNode<T> *,int> P(root,0);
        Q.push(P);
        while(!Q.empty())
        {
            pair<GTNode<T> *,int> temp = Q.front();
            Q.pop();
            if(temp.second==K)
            {
                cout<<temp.first->data<<' ';
                continue;
            }
            for(int i=0;i<temp.first->children.size();i++)
            {
                pair<GTNode<T> *,int> childpair;
                childpair.first = temp.first->children[i];
                childpair.second = temp.second + 1;
                Q.push(childpair);
            }
        }
    }


private:
    static bool printRouteToElHelper(GTNode<T> * curr,T & el,vector<GTNode<T> *> & V)
    {
        if(curr->data == el)
        {
            V.push_back(curr);
            cout<<el<<' ';
            return true;
        }
        for(int i=0;i<curr->children.size();i++)
        {
            bool childans = printRouteToEl(curr->children[i],el);
            if(childans==true)
            {
                V.push_back(curr);
                cout<<curr->data<<' ';
                return true;
            }
        }
        return false;
    }

public:
    void printRouteToEl(const T & el) const
    {
        vector<GTNode<T> *>V;
       bool ans =  printRouteToEl(root,el);
       if(ans==false)
       {
           cout<<el<<" doesn't exist in the tree"<<endl;
       }
    }

public:
    void printPath(vector <const GTNode<T> *> & V)
    {
        for(int i=0;i<V.size();i++)
        {
            cout<<V[i]->data<<"-->";
        }
        cout<<endl;
    }
/*
    void printLargestAndSecongLargest()
    {
        pair<GTNode<T> *,GTNode<T> *> P = getSecondLargestNode(root);
        cout<<"The Largest Node is : "<<P.first->data<<endl<<"The Second Largest Node is : "<<P.second->data<<endl;
    }*/

private:

    static void printAllRoutesToLeaf(GTNode<T> * curr,vector<GTNode<T> *> & V)
    {
        if(curr->children.empty())
        {
            V.push_back(curr);
            printPath(V);
            V.pop_back();
            return;
        }
        for(int i=0;i<curr->children.size();i++)
        {
            V.push_back(curr);
            printAllRoutesToLeaf(curr->children[i],V);
            V.pop_back();
        }
    }



   /* static  pair<GTNode<T> *,GTNode<T> *> getSecondLargestNode(GTNode<T> * curr)
    {
        if(curr->children.size()==0)
        {
            pair<GTNode<T> *,GTNode<T> *> P1(curr,0);
            return P1;
        }

        pair<GTNode<T> *,GTNode<T> *> P2(curr,0);
        for(int i=0;i<curr->children.size();i++)
        {
            pair<GTNode<T> *,GTNode<T> *> P3 = getSecondLargestNode(curr->children[i]);
            if(P3.first->data>P2.first->data)
            {
                P2.second = P2.first;
                P2.first = P3.first;
                if(P3.second->data>P2.second->data)
                {
                    P2.second = P3.second;
                }
            }
            else
            {
                if(P3.first->data>P2.second->data)
                {
                    P2.second = P3.first;
                }
            }
            return P2;
        }
    }*/

public:
    const T & getSecondLargest() const
    {
        if(root==NULL || root->children.size()==0)
        {
            throw "The tree doesn't have enough nodes : ";
        }
        pair<const GTNode<T> *,const GTNode<T> *> P = getSecondLargestHelper(root);
        cout<<"The second largest is : "<<P.second->data;
    }

private:
    static pair<const GTNode<T> *,const GTNode<T> *> getSecondLargestHelper(const GTNode<T> * curr)
    {
        pair<const GTNode<T> *,const GTNode<T> *> ans(curr,0),childans;
        for(int i=0;i<curr->children.size();i++)
        {
            childans = getSecondLargestHelper(curr->children[i]);

                if(childans.first->data > ans.first->data)
                {
                    if(childans.second==NULL || childans.second->data<ans.first->data)
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

};

#endif // GENERIC_TREE_H
