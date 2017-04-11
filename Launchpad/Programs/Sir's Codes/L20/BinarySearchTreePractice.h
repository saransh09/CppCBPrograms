#ifndef BST_Pr
#define BST_Pr
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
template<typename T>
class BTNode {
	T data;
	BTNode *left, *right;
public:
	BTNode() : left(0), right(0) {}
	BTNode(const T & el) : data(el), left(0), right(0) {}
	template<typename U>
	friend class BinarySearchTree;
};
template<typename T>
class BinarySearchTree {
	BTNode<T> *root;
public:
	BinarySearchTree() : root(0) {}
	void insert(const T & el) {
		root = insertTreeHelper(el);
	}
private:
	static BTNode<T> * insertTreeHelper(BTNode<T> *curr, const T & el) {
		if(curr == NULL) {
			BTNode<T> * temp = new BTNode<T>(el);
			return temp;
		}
		if(curr -> data > el) {
			curr -> left = insertTreeHelper(curr -> left,el);
		}
		else {
			curr -> right = insertTreeHelper(curr -> right, el);
		}
		return curr;
	}
public:
	void insertTreeIterative(const T & el) {
		BTNode<T> *newnode = new BTNode<T>(el);
		if (root == NULL) {
			root = newnode;
			return;
		}
		BTNode<T> *it = root, *prevofit = NULL;
		while(it!=NULL) {
			prevofit = it;
			if (it -> data < el) {
				it = it -> right;
			}
			else {
				it = it -> left;
			}
		}
		if (prevofit -> data < el) {
			prevofit -> right = newnode;
		}
		else {
			prevofit -> left = newnode;
		}
		return;
	}
public:
	void constructTreeUsingPreOrder(const vector<T> & pre) {
		if (root != NULL){
			throw "Tree already exists";
		}
		root = constructTreeUsingPreOrderHelper(pre, 0, pre.size() - 1);
	}
private:
	static BTNode<T> * constructTreeUsingPreOrderHelper(const vector<T> & pre, int start, int end) {
		if (start == end) {
			BTNode<T> * curr = new BTNode<T>(pre[start]);
			return curr;
		}
		if (start > end) {
			return NULL;
		}
		BTNode<T> * curr = new BTNode<T>(pre[start]);
		int i;
		for ( i = start+1; i <= end; i++ ) {
			if ( pre[i] > pre[start] ) {
				break;
			}
		}
		curr -> left = constructTreeUsingPreOrderHelper(pre, start+1, i -1);
		curr -> right = constructTreeUsingPreOrderHelper(pre, i, end);
	}
public:
	BTNode<T> * minValueNode(){
		if (!root) {
			throw "Tree does not exist";
		}
		BTNode<T> * curr = minValueNodeHelper(root);
		return curr;
	}
private:
	static BTNode<T> * minValueNodeHelper(BTNode<T> * curr) {
		BTNode<T> * temp = curr;
		while(curr -> left != NULL) {
			curr = curr -> left;
		}
		return curr;
	}
public:
	



};

#endif