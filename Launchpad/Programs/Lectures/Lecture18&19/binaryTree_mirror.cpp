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
        cout<<"Does"<<el<<"have left tree";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            curr->left = createTreeHelper();
        }
        cout<<"Does"<<el<<"have right tree";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            curr->right = createTreeHelper();
        }
        return curr;
    }
    public:
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
   /* public:
    GenericTree(const GenericTree & T1) : root(0) {
        if (T1.root == NULL) {
            return;
        }
        root = copyTreeHelper(T1.root);
        return;
    }
    GenericTree & operator=(const GenericTree & T1) {
        clear();
        if (T1.root == NULL) {
            return *this;
        }
        root = copyTreeHelper(T1.root);
        return *this;
    }
    private:
    static GTNode<T> * copyTreeHelper(const GTNode<T> * otheraddress) {
        GTNode<T>  *curr = new GTNode<T>(otheraddress->data);
        for (int i = 0; i < otheraddress->children.size(); i++) {
            GTNode<T> * childaddress = copyTreeHelper(otheraddress->children[i]);
            curr->children.push_back(childaddress);
        }
        return curr;
    }

    public:
    void createTreeLevelWise() {
        if (root) {
            throw "Tree already Exist";
        }
        queue<GTNode<T> *> Q;

        cout<<"enter data";
        T el;
        cin>>el;
        root = new GTNode<T>(el);
        Q.push(root);

        while(!Q.empty())
        {
            cout<<"Enter number of childs";
            int childs;
            cin>>childs;
            for(int i=0;i<childs;i++)
            {
                cout<<"enter data :";
                T el;
                cin>>el;
                GTNode<T> * c = new GTNode<T>(el);
                Q.front()->children.push_back(c);
                Q.push(c);
            }
            Q.pop();
        }


    }

    static const GTNode<T> * getLargestHelper(const GTNode<T> * cur)
    {
        const GTNode<T> * largest = cur;
        for(int i=0;i<cur->children.size();i++)
        {
            const GTNode<T> * childAns = getLargestHelper(cur->children[i]);
            if(largest->data < childAns->data)
            {
                largest = childAns;
            }
        }
        return largest;
    }


    const T & getLargestData() const {
        if(root==0)
        {
            throw "Empty Tree !! \n";
        }
        const GTNode<T> * largest = getLargestHelper(root);
        return largest->data;
    }


    void printAllElementsAtDepth(int k) const {
        if(root==0)
        {
            return ;
        }

        queue<pair<GTNode<T>* , int> > Q;
        //pair<GTNode<T>* , int> Q;
        pair<GTNode<T> *, int> P(root,0);
        Q.push(P);
        while(!Q.empty())
        {
            pair<GTNode<T>* ,int> temp = Q.front();
            Q.pop();
            if(temp.second ==k)
            {
                cout<<temp.first->data<<" ";
                continue;
            }
            for(int i=0;i<temp.first->children.size();i++)
            {
                pair<GTNode<T> * ,int > childpair;
                childpair.first = temp.first->children[i];
                childpair.second = temp.second + 1;
                Q.push(childpair);
            }
        }

    }

    bool printRootToElPath(const T & el) const
    {
        vector<const GTNode<T> *> V;
        bool ans = printRootToElHelper(root,el,V);

        if(ans==true)
        {
            cout<<endl<<V.size();
            for(int i=0; i<V.size(); i++)
            {
                cout<<V[i].data<<" ";
            }
        }
        return ans;
    }

    static bool printRootToElHelper(const GTNode<T>* curr, const T & el, vector<const GTNode<T> *> V)
    {
        if(curr->data==el)
        {
            V.push_back(el);
            return true;
        }

        for(int i=0;i<curr->children.size();i++)
        {
            GTNode<T> * childAddress = curr->children[i];
            bool ans = printRootToElHelper(childAddress,el,V);
            if(ans==true)
            {
                V.push_back( curr->data );
                return true;
            }
        }
        return false;

    }*/

    void mirror()
    {
        if(root==0)
            return;

        BinaryTree<T> B1;
        root = mirrorHelper(root,);
    }

    BTNode<T> * mirrorHelper(BTNode<T> * curr)
    {

    }

};

int main()
{
    BinaryTree<int> B;
    B.createTree();
    B.printPreOrder();
    return 0;
}

