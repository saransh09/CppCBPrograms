#ifndef GENERIC_TREE_H
#define GENERIC_TREE_H
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
class GTNode {
    T data;
    vector<GTNode *> children;
    public:
    GTNode() {}
    GTNode(const T & el) : data(el) {}
    template<typename U>
    friend class GenericTree;
};
template<typename T>
class GenericTree {
    GTNode<T> * root;
    public:
    GenericTree() : root(0) {}
    void createTree() {
        if (root!= NULL) {
            throw "Tree already exist";
        }
        root = createTreeHelper();
    }
    private:
    static GTNode<T> * createTreeHelper() {
        T el;
        cout << "Enter data for node ";
        cin >> el;
        GTNode<T> * currnode = new GTNode<T>(el);
        int childs;
        cout << "Enter Number of childs";
        cin >> childs;
        for (int i =0 ; i < childs; i++) {
            GTNode<T>* childaddress = createTreeHelper();
            currnode->children.push_back(childaddress);
        }
        return currnode;
    }
    public:
    void printPreOrder() const {
        printPreOrderHelper(root);
    }
    private:
    static void printPreOrderHelper(const GTNode<T> * curr) {
        cout << curr->data << " ";
        for (int i = 0; i < curr->children.size(); i++) {
            printPreOrderHelper(curr->children[i]);
        }
    }
    public:
    ~GenericTree() {
        clear();
    }
    void clear() {
        clearHelper(root);
        root = NULL;
    }
    private:
    static void clearHelper(GTNode<T> * curr) {
        for (int i = 0; i < curr->children.size(); i++) {
            clearHelper(curr->children[i]);
        }
        delete curr;
    }
    public:
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
        T el;
        int childcount;
        cout << "Enter data for root node ";
        cin >> el;
        root = new GTNode<T>(el);
        queue<GTNode<T> *> Q;
        Q.push(root);
        while (!Q.empty()) {
            GTNode<T> * curr = Q.front();
            Q.pop();
            cout << "Enter number of childs for " << curr->data <<" ";
            cin >> childcount;
            for (int i = 0; i < childcount; i++) {
                cout << "Enter data for " << i+1 << " child ";
                cin >> el;
                GTNode<T> * childnode = new GTNode<T>(el);
                curr->children.push_back(childnode);
                Q.push(childnode);
            }
        }
    }
    const T & getLargestData() const {
        if (root == NULL) {
            throw "Tree is Empty!";
        }
        const GTNode<T> * largest = getLargestHelper(root);
        return largest->data;
    }

    static const GTNode<T> * getLargestHelper(const GTNode<T> * cur) {
        const GTNode<T> * largest = cur;
        for (int i = 0; i < cur->children.size(); i++) {
            const GTNode<T> * childans = getLargestHelper(cur->children[i]);
            if (largest->data < childans->data) {
                largest = childans;
            }
        }
        return largest;
    }
    void printAllElementsAtDepthK(int K) const {
        if (root == NULL) {
            return;
        }
        queue<pair<GTNode<T>*, int> > Q;
        pair<GTNode<T> *, int> P(root, 0);
        Q.push(P);
        while (!Q.empty()) {
            pair<GTNode<T> *, int> temp = Q.front();
            Q.pop();
            if (temp.second == K) {
                cout << temp.first->data << " ";
                continue;
            }
            for(int i = 0; i < temp.first->children.size(); i++) {
                pair<GTNode<T> *, int> childpair;
                childpair.first = temp.first->children[i];
                childpair.second = temp.second + 1;
                Q.push(childpair);
            }
        }
    }
    void printRootToElPath(const T & el) const {
        vector<const GTNode<T> * > V;
        bool ans = printRootToElHelper(root, el, V);
    }
    private:
    static bool printRootToElHelper(const GTNode<T> * curr, const T & el, vector<const GTNode<T> *> & V) {
        if (curr->data == el) {
            V.push_back(curr);
            return true;
        }
        for (int i = 0; i < curr->children.size(); i++) {
            bool chilans = printRootToElHelper(curr->children[i], el, V);
            if (chilans == true) {
                V.push_back(curr);
                return true;
            }
        }
        return false;
    }
};



#endif
