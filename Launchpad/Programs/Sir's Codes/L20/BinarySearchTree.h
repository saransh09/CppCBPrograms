#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
template<typename T>
class BTNode {
    T data;
    BTNode * left, *right;
    public:
    BTNode() : left(0), right(0) {}
    BTNode(const T & el) : data(el), left(0), right(0) {}
    template<typename U>
    friend class BinarySearchTree;
};

template <typename T>
class BinarySearchTree {
    BTNode<T> * root;
    public:
    BinarySearchTree() : root(0) {}
    void insert(const T & el) {
        root = insertHelper(root, el);
    }
    void insertIterative(const T & el) {
        BTNode<T> * newnode = new BTNode<T>(el);
        if (root == NULL) {
            root = newnode;
            return;
        }
        BTNode<T> *it = root, *prevOfit = NULL;
        while(it != NULL) {
            prevOfit = it;
            if (it->data < el) {
                it = it->right;
            } else {
                it = it->left;
            }
        }
        if (prevOfit->data < el) {
            prevOfit->right = newnode;
        } else {
            prevOfit->left = newnode;
        }
        return;

    }
    private:
    static BTNode<T> * insertHelper(BTNode<T> * curr, const T & el) {
        if (curr == NULL) {
            BTNode<T> * temp = new BTNode<T>(el);
            return temp;
        }
        if (curr->data > el) {
            curr->left = insertHelper(curr->left, el);
        } else {
            curr->right = insertHelper(curr->right, el);
        }
        return curr;
    }
    public:
    void constructTreeUsingPreOrder(const vector<T> & pre) {
        if (root != NULL) {
            throw "Tree already exists";
        }
        root = constructTreeUsingPreOrderHelper(pre, 0, pre.size() -1);
    }
    private:
    static BTNode<T> * constructTreeUsingPreOrderHelper(const vector<T> & pre, int start, int end) {
        if (start == end) {
            BTNode<T> * cur = new BTNode<T>(pre[start]);
            return cur;
        }
        if (start > end) {
            return NULL;
        }
        BTNode<T> * cur = new BTNode<T>(pre[start]);
        int i;
        for ( i = start+1; i <= end; i++) {
            if (pre[i] > pre[start]) {
                break;
            }
        }
        cur->left = constructTreeUsingPreOrderHelper(pre, start+1, i-1);
        cur->right = constructTreeUsingPreOrderHelper(pre, i, end);
        return cur;

    }







};

#endif
