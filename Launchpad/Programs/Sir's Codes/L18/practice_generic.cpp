// #ifndef GENERIC_TREE_H
// #define GENERIC_TREE_H
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
};