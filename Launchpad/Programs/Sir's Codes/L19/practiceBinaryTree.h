#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
template<typename T>
class BTNode{
	T data;
	BTNode *left, *right;
public:
	BTNode() : left(0), right(0) {}
	BTNode(const T & el) : data(el), left(0), right(0) {}
	template<typename U>
	friend class BinaryTree; 
};
template<typename T>
class BinaryTree{
	BTNode<T> * root;
public:
	BinaryTree() : root(0) {}
	void createTree(){
		if(root!=NULL){
			throw "The tree has already been defined";
		}
		root = createTreeHelper();
	}
private:
	static BTNode<T> * createTreeHelper(){
		T el;
		cout<<"Enter the data for the node";
		cin>>el;
		BTNode<T> * currnode = new BTNode<T>(el);
		char ch;
		cout<<"Does "<< el << " has a left child (y/n)";
		cin>>ch;
		if (ch=='y' || ch=='Y'){
			currnode->left = createTreeHelper();
		} 
		cout<<"Does "<< el << " has a right child (y/n)";
		cin>>ch;
		if (ch=='y' || ch=='Y'){
			currnode->right = createTreeHelper();
		}
		return currnode;
	}
public:
	void printPreOrder() const{
		printPreOrderHelper(root);
	}
	void printInorder() const{
		printInorderHelper(root);
	}
	void printPostOrder() const{
		printPostOrderHelper(root);
	}
private:
	static void printPreOrderHelper(const BTNode<T> * curr){
		if(curr==NULL){
			return;
		}
		cout << curr->data << ' ';
		printPreOrderHelper(curr->left);
		printPreOrderHelper(curr->right);
	}
	static void printInorderHelper(const BTNode<T> * curr){
		if(curr==NULL){
			return;
		}
		printInorderHelper(curr->left);
		cout<< curr->data << ' ';
		printInorderHelper(curr->right);
	}
	static void printPostOrderHelper(const BTNode<T> * curr){
		if(curr==NULL){
			return;
		}
		printPostOrderHelper(curr->left);
		printPostOrderHelper(curr->right);
		cout<< curr->data << ' ';
	}
public:
	~BinaryTree(){
		clear();
	}
	void clear(){
		clearHelper(root);
		root = NULL;
	}
private:
	static void clearHelper(BTNode<T> * curr){
		if(curr==NULL){
			return;
		}
		clearHelper(curr->left);
		clearHelper(curr->right);
		delete curr;
	}
public:
	BinaryTree(const BinaryTree & T1) : root(0){
		if (T1.root == NULL){
			return;
		}
		root = copyTreeHelper(T1.root);
		return;
	}
	BinaryTree & operator=(const BinaryTree & T1){
		clear();
		if(T1.root == NULL){
			return;
		}
		root = copyTreeHelper(T1.root);
		return *this;
	}
private:
	static BTNode<T> * copyTreeHelper(const BTNode<T> * otheraddress) {
		if(otheraddress==NULL){
			return NULL;
		}
		BTNode<T> *curr = new BTNode<T>(otheraddress->data);
		curr->left = copyTreeHelper(otheraddress->left);
		curr->right = copyTreeHelper(otheraddress->right);
	}
public:
	void createTreeLevelWise() {
		if (root){
			throw "Tree already exisits";
		}
		T el;
		char ch;
		cout<<"Enter the data for root node";
		cin>>el;
		root = new BTNode<T>(el);
		queue<BTNode<T> *> Q;
		Q.push(root);
		while(!Q.empty()){
			BTNode<T> * curr = Q.front();
			Q.pop();
			cout<<"Does "<< el << " has a left child (y/n)";
			cin>>ch;
			if (ch=='y' || ch=='Y'){
				cout<<"Enter the data for the node : ";
				cin>>el;
				BTNode<T> * leftchild = new BTNode<T>(el);
				curr->left = leftchild;
				Q.push(leftchild);
			} 
			cout<<"Does "<< el << " has a right child (y/n)";
			cin>>ch;
			if (ch=='y' || ch=='Y'){
				cout<<"Enter the data for the node : ";
				cin>>el;
				BTNode<T> *rightchild = new BTNode<T>(el);
				curr->right = rightchild;
				Q.push(rightchild);
			}
		}
	}
	const T & getLargerData() const{
		if(root==NULL){
			throw "Tree is empty";
		}
		const BTNode<T> *largest = getLargerDataHelper(root);
		return largest->data;
	}
private:
	static const BTNode<T> * getLargerDataHelper(const BTNode<T> * curr){
		if(curr == NULL){
			return NULL;
		}
		const BTNode<T> *largest = curr;
		const BTNode<T> *leftLargest = getLargerDataHelper(curr->left);
		if (leftLargest && leftLargest->data > largest -> data){
			largest = leftLargest;
		}
		const BTNode<T> *rightLargest = getLargerDataHelper(curr -> right);
		if (rightLargest && rightLargest -> data > largest ->data){
			largest = rightLargest;
		}
		return largest;
	}
public:
	void printAllElementsAtDepthK(int K) const{
		if(root == NULL){
			return;
		}
		queue<pair<BTNode<T> *, int> > Q;
		pair<BTNode<T> *, int> P(root,0);
		Q.push(P);
		while(!Q.empty()) {
			pair<BTNode<T> *,int> temp = Q.front();
			Q.pop();
			if(temp.second == K){
				cout << temp.first->data << ' ';
				continue;
			}
			if(temp.first -> left){
				pair<BTNode<T> *,int> childpair;
				childpair.first = temp.first->left;
				childpair.second = temp.second + 1;
				Q.push(childpair);
			}
			if(temp.first -> right){
				pair<BTNode<T> *,int> childpair;
				childpair.first = temp.first->right;
				childpair.second = temp.second + 1;
				Q.push(childpair);
			}
		}
	}
	void printRootToElPath(const T & el) const{
		vector<const BTNode<T> *> V;
		bool ans = printRootToElPathHelper(root, el, V);
		for (int i = V.size(); i>=0;i--){
			cout << V[i] << ' ';
		}
		if (ans == false){
			cout << el << "doesn't exist in the tree" << endl;
		}
	}
private:
	static bool printRootToElPathHelper(const BTNode<T> * curr, const T & el, vector<BTNode<T> *> & V){
		if (curr == NULL){
			return false;
		}
		bool childans;
		childans = printRootToElPathHelper(curr -> left, el, V);
		if (childans ==  true){
			V.push_back(curr);
			return true;
		}
		childans = printRootToElPathHelper(curr -> right, el, V);
		if ( childans = true){
			V.push_back(childans);
			return true;
		}
		return false;
	}
// 	void mirror(){
// 		if (root == NULL){
// 			throw "The tree does not exits";
// 		}
// 		BTNode<T> * temp;
// 		mirrorHelper(root,temp);
// 		root = temp;
// 		delete temp;
// 	}
// private:
// 	static BTNode<T> * mirrorHelper(const BTNode<T> * curr, BTNode<T> * temp){
// 		if (curr == NULL){
// 			return;
// 		}
// 		BTNode<T> * temp;
// 		mirrorHelper(node -> left);
// 		mirrorHelper(node -> right);

// }
	int height() const{
		if(root == NULL){
			throw "The tree does not exist";
		}
		return heightHelper(root);
	}
private:
	static int heightHelper(const BTNode<T> * curr){
		if (curr == NULL){
			return 0;
		}
		return 1 + max(height(curr -> left), height(curr -> right));
	}

	int diameter() const{
		if (root == NULL){
			throw "The tree is empty";
		}
		int d = diameterHelper(root);
		return d;
	}
private:
	static int diameterHelper(const BTNode<T> * curr){
		int lHeight = height(curr -> left);
		int rHeight = height(curr -> right);
		int lDiameter = diameterHelper(curr->left);
		int rDiameter = diameterHelper(curr->right);
		return max(1+lHeight+rHeight,max(lDiameter,rDiameter));
	}
public:
	void deleteAllHalfNodes() {
		if(root==NULL){
			return;
		}
		deleteAllHalfNodesHelper(root);
	}
private:
	static void deleteAllHalfNodesHelper(BTNode<T> * curr){
		if(curr -> left && !(curr -> right)) {
			clear(curr->left);
		}
		else if(curr -> right && !(curr -> left)){
			clear(curr -> right);
		}
		deleteAllHalfNodesHelper(curr->left);
		deleteAllHalfNodesHelper(curr->right);
		return;
	}
public:
	void delteAllLeafNodes(){
		if (root==NULL){
			throw "The treee is empty";
		}
		delteAllLeafNodesHelper(root);
		return;
	}
private:
	static void delteAllLeafNodesHelper(BTNode<T> * curr){
		if(curr->left->left==NULL && curr->left->right == NULL){
			delete curr->left;
		}
		else if(curr->right->left == NULL && curr->right->right == NULL){
			delete curr->right;
		}
		delteAllLeafNodesHelper(curr->left);
		delteAllLeafNodesHelper(curr->right);
	}
public:
	void printNodesWithNoSiblings() const{
		if (root == NULL){
			return
		}
	}



};



#endif
