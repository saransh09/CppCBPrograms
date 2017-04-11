#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
class BTNode {
    T data;
    BTNode * left, *right;
    public:
    BTNode() : left(0), right(0) {}
    BTNode(const T & el) : data(el), left(0), right(0) {}
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
        BTNode<T> * currnode = new BTNode<T>(el);
        char ch;
        cout << "Does " << el <<" has left child (y/n) ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            currnode->left = createTreeHelper();

        }
        cout << "Does " << el <<" has right child (y/n) ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            currnode->right = createTreeHelper();
        }
        return currnode;
    }
    public:
    void printPreOrder() const {
        printPreOrderHelper(root);
    }
    private:
    static void printPreOrderHelper(const BTNode<T> * curr) {
        if (curr == NULL) {
            return;
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
        if (curr == NULL) {
            return;
        }
        clearHelper(curr->left);
        clearHelper(curr->right);
        delete curr;
    }
    public:
    BinaryTree(const BinaryTree & T1) : root(0) {
        if (T1.root == NULL) {
            return;
        }
        root = copyTreeHelper(T1.root);
        return;
    }
    BinaryTree & operator=(const BinaryTree & T1) {
        clear();
        if (T1.root == NULL) {
            return *this;
        }
        root = copyTreeHelper(T1.root);
        return *this;
    }
    private:
    static BTNode<T> * copyTreeHelper(const BTNode<T> * otheraddress) {
        if (otheraddress == NULL) {
            return NULL;
        }
        BTNode<T>  *curr = new BTNode<T>(otheraddress->data);
        curr->left = copyTreeHelper(otheraddress->left);
        curr->right = copyTreeHelper(otheraddress->right);
        return curr;
    }

    public:
    void createTreeLevelWise() {
        if (root) {
            throw "Tree already Exist";
        }
        T el;
        char ch;
        cout << "Enter data for root node ";
        cin >> el;
        root = new BTNode<T>(el);
        queue<BTNode<T> *> Q;
        Q.push(root);
        while (!Q.empty()) {
            BTNode<T> * cur = Q.front();
            Q.pop();
            cout << "Does " << curr->data << " has left child(y/n)";
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                cout << "Enter data ";
                cin >> el;
                BTNode<T> *leftchild = new BTNode<T>(el);
                curr->left = leftchild;
                Q.push(leftchild);
            }
            cout << "Does " << curr->data << " has right child(y/n)";
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                cout << "Enter data ";
                cin >> el;
                BTNode<T> *rightchild = new BTNode<T>(el);
                curr->right = rightchild;
                Q.push(rightchild);
            }
        }
    }
    const T & getLargestData() const {
        if (root == NULL) {
            throw "Tree is Empty!";
        }
        const BTNode<T> * largest = getLargestHelper(root);
        return largest->data;
    }

    static const BTNode<T> * getLargestHelper(const BTNode<T> * cur) {
        if (curr == NULL) {
            return NULL;
        }
        const BTNode<T> * largest = cur;
        const BTNode<T> *leftlargest = getLargestHelper(curr->left);
        if (leftlargest && leftlargest->data > largest->data) {
            largest = leftlargest;
        }
        const BTNode<T> *rightlargest = getLargestHelper(curr->right);
        if (rightlargest && rightlargest->data > largest->data) {
            largest = rightlargest;
        }
        return largest;
    }
    void printAllElementsAtDepthK(int K) const {
        if (root == NULL) {
            return;
        }
        queue<pair<BTNode<T>*, int> > Q;
        pair<BTNode<T> *, int> P(root, 0);
        Q.push(P);
        while (!Q.empty()) {
            pair<BTNode<T> *, int> temp = Q.front();
            Q.pop();
            if (temp.second == K) {
                cout << temp.first->data << " ";
                continue;
            }
            if (temp.first->left) {
                pair<BTNode<T> *, int> childpair;
                childpair.first = temp.first->left;
                childpair.second = temp.second + 1;
                Q.push(childpair);
            }
            if (temp.first->right) {
                pair<BTNode<T> *, int> childpair;
                childpair.first = temp.first->right;
                childpair.second = temp.second + 1;
                Q.push(childpair);
            }
        }
    }
    void printRootToElPath(const T & el) const {
        vector<const BTNode<T> * > V;
        bool ans = printRootToElHelper(root, el, V);
        for (int i = V.size(); i >= 0; i--) {
            cout << V[i]->data << " ";
        }
        if (ans == false) {
            cout << el << " doesn't exist in the tree" << endl;
        }
    }
    private:
    static bool printRootToElHelper(const BTNode<T> * curr, const T & el, vector<const BTNode<T> *> & V) {
        if (curr == NULL) {
            return false;
        }
        if (curr->data == el) {
            V.push_back(curr);
            return true;
        }
        bool childans;
        childans = printRootToElHelper(curr->left, el, V);
        if (chilans == true) {
            V.push_back(curr);
            return true;
        }
        childans = printRootToElHelper(curr->right, el, V);
        if (chilans == true) {
            V.push_back(curr);
            return true;
        }
        return false;
    }
    void mirror() {

    }
};



#endif
