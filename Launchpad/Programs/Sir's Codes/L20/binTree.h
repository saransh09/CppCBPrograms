#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
template<typename T>
class BTNode {
	T data;
	BTNode * left;
	BTNode * right;
public:
	BTNode() : left(0), right(0) {}
	BTNode(const T & el) : data(el), left(0), right(0) {}
	template<typename U>
	friend class BinarySeachTree;
};
template<typename T>
class BinarySearchTree {
	BTNode<T> * root;
public:
	BinarySearchTree() : root(0) {}
	void insert(const T & el){
		root = insertHelper(root, el);
	}
	void insertIterative(const T & el) {
		BTNode<T> * newnode = new BTNode<T>(el) {}
		if(root == NULL) {
			root = newnode;
			return;
		}
		BTNode<T> *it = root, *prevofit = NULL;
		while(it != NULL) {
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
private:
	static BTNode<T> * insertHelper(BTNode<T> * curr, const T & el) {
		if ( curr == NULL) {
			BTNode<T> * temp = new BTNode<T>(el);
			return temp;
		}
		if ( curr -> data < el) {
			curr -> left = insertHelper( curr -> left, el);
		}
		else {
			curr -> right = insertHelper( curr -> right, el);
		}
		return curr;
	}
public:
	void constructTreeUsingPreOrder(const vector<T> & pre) {
		if (root != NULL) {
			throw "Tree already exist";
		}
		root = constructTreeUsingPreOrderHelper(pre, 0, pre.size() - 1);
	}
private:
	void constructTreeUsingPreOrderHelper(const vector<T> & pre, int start, int end) {
		if (start == end){
			BTNode<T> * curr = new BTNode<T>(pre[start]);
			return curr;
		}
		else if (start > end){
			return NULL;
		}
		BTNode<T> * curr = new BTNode<T>(pre[start]);
		// int i =0;
		for(int i=0; i <= end; i++) {
			
		}
	}

};



#endif