#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
template<typename T>
class BTNode{
	T el;
	BTNode * left;
	BTNode * right;
	template<typename U>
	friend class BinaryTree;
};
template<typename T>
class BinaryTree{
	BTNode<T> * root;
	public:
		//Constructors
		BinaryTree(): root(0) {}
		BinaryTree(const T el) : root(el) {}
		//Destructor
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
		void createTree(){
			if(root){
				throw "The tree already exists";
			}
			root = createTreeHelper(root);
		}
	// private:
		// static BTNode<T> * createTreeHelper(BTNode<T> * curr){
		// 	T el;
		// 	cout<<"Enter the data : ";
		// 	cin>>el;
		// 	BTNode<T> * currnode = new BTNode<T>(el);
		// 	char ch;
		// 	cout<<"Does "<< el << " has left child"
		// }
		void createTreeLevelWise(){
			if(root){
				throw "Tree already exists";
			}
			T el;
			char ch;
			cout<<"Enter the root data";
			cin >> el;
			root = new BTNode<T>(el);
			queue<BTNode<T> * > Q;
			Q.push(root);
			while(!Q.empty()){
				BTNode<T> * curr = Q.front();
				Q.pop();
				cout << "Does " << curr->data << " has left child(y/n)";
	            cin >> ch;
	            if (ch == 'y' || ch == 'Y'){
	                cout << "Enter data ";
	                cin >> el;
	                BTNode<T> *leftchild = new BTNode<T>(el);
	                curr->left = leftchild;
	                Q.push(leftchild);
				}
		}

};

int main(){
	return 0;
}