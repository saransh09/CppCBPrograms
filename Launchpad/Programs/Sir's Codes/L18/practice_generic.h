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
    static void clearHelper(GTNode<T> * curr){
        for (int i=0; i < curr->children.size();i++){
            clearHelper(curr->children[i]);
        }
        delete curr;
    }
    public:
    GenericTree(const GenericTree & T1) : root(0) {
        if (T1.root == NULL){
            return;
        }
        root = copyTreeHelper(T1.root);
        return;
    }
    GenericTree & operator=(const GenericTree & T1){
        clear();
        if(T1.root == NULL){
            return *this;
        }
        root = copyTreeHelper(T1.root);
        return *this;
    }
    private:
    static GTNode<T> * copyTreeHelper(const GenericTree<T> * otheradress){
        GTNode<T> * curr = new GTNode<T>(otheradress->data);
        for(int i=0;i<otheradress->children.size();i++){
            GTNode<T> * childaddress = copyTreeHelper(otheradress->children[i]);
            curr->children.push_back(childaddress);
        }
        return curr;
    }
    void createTreeLevelWise(){
        if(root){
            throw "Tree already Exists";
        }
        T el;
        int childcount;
        cout << "Enter data for the root node ";
        cin>>el;
        root = new GTNode<T>(el);
        queue<GTNode<T> *> Q;
        Q.push(root);
        while(!Q.empty()){
            GTNode<T> * curr = Q.front();
            Q.pop();
            cout<<"Enter numbe of childs for "<<curr->data<<" ";
            cin>>childcount;
            for(int i=0;i<childcount;i++){
                cout<<"Enter data for "<<i+1<<" child ";
                cin>>el;
                GTNode<T> * childnode = new GTNode<T>(el);
                curr->children.push_back(childnode);
                Q.push(childnode);
            }
        }
    }
    const T & getLargetData() const{
        if (root == NULL){
            throw "Tree is Empty";
        }
        const GTNode<T> * largest = getLargetHelper(root);
        return largest->data;
    }
    static const GTNode<T> * getLargetHelper(const GTNode<T> * curr){
        const GTNode<T> * largest = curr;
        for (int i=0;i<curr->children.size();i++){
            const GTNode<T> * childans = getLargetHelper(curr->children[i]);
            if(largest->data < childans->data){
                largest = childans;
            }
        }
        return largest;
    }
    void printAllElementsAtDepthK(int K) const{
        if(root==NULL){
            throw "The tree is empty";
        }
        queue<pair<GTNode<T>*,int> > Q;
        pair<GTNode<T> *,int> P(root,0);
        Q.push(P);
        while (!Q.empty()){
            pair<GTNode<T> *,int> temp = Q.front();
            Q.pop();
            if(temp.second == K){
                cout<<temp.first->data<<" ";
                continue;
            }
            for(int i=0;i<temp.first->children.size();i++){
                pair<GTNode<T> *,int> childpair;
                childpair.first = temp.first->children[i];
                childpair.second = temp.second + 1;
                Q.push(childpair);
            }
        }
    }
    void printRootToElPath(const T & el) const{
        vector<const GTNode<T> *> V;
        bool ans = printRootToElHelper(root,el,V);
        for(int i=V.size();i>0;i--){
            cout<<V[i]->data<<"-->";
        }
        if(ans==false){
            cout<<"The entered element was not found in the tree";
        }
    }

    private:
    static bool printRootToElHelper(const GTNode<T> * curr, const T & el, vector<const GTNode<T> *> & V){
        if(curr->data = el){
            V.push_back(curr);
            return true;
        }
        for(int i=0;i<curr->children.size();i++){
            bool childans = printRootToElHelper(curr->children[i],el,V);
            if(childans==true){
                V.push_back(curr);
                return true;
            }
        }
        return false;
    }
    public:
    int getHeight() const {
        int b=0;
        getHeightHelper(root,b);
        return b+1;
    }
    private:
    static int getHeightHelper(GTNode<T> * curr,int & h){
        if(curr!=NULL){
            return 0;
        }
        for(int i=0;i<curr->children.size();i++){
            GTNode<T> * childans = curr->children[i];
            int a = getHeightHelper(childans,h);
            if(a>h){
                h=a;
            }
        }
        return h;
    }
public:
    void printAllElementsAtDepthKUsingQueue(int k){
        if(root==NULL){
            throw "The tree is empty";
        }
        queue<pair<GTNode<T> *,int> > Q;
        pair<GTNode<T> *,int> P(root,0);
        Q.push(P);
        while(!Q.empty()){
            pair<GTNode<T> *,int> temp = Q.front();
            Q.pop();
            if(temp.second == k){
                cout<<temp.first->data<<' ';
                continue;
            }
            for(int i=0;i<temp->children.size();i++){
                pair<GTNode<T> *, int> childpair;
                childpair.first = temp.first->children[i];
                childpair.second = temp.second + 1;
                Q.push(childpair);
            }
        }
    }

    void printAllElementsAtDepthKUsingRecursion() const{
        if(root==NULL){
            throw "The tree is empty";
        }
        cout<<"Print the depth at which the elements are needed";
        int k;
        cin>>k;
        if(k>getHeight(root)){
            throw "The depth entered exceeds the depth of the tree";
        }
        printAllElementsAtDepthKUsingRecursionHelper(root,k,1);
    }
private:
    static GTNode<T> * printAllElementsAtDepthKUsingRecursionHelper(GTNode<T> * curr,int k,int a){
        if(k==0){
            cout<<curr->data;
            return NULL;
        }
        for(int i=0;i<curr->children.size();i++){
            GTNode<T> * childans = curr->children[i];
            if(a==k){
                cout<<childans->data<<' ';
                continue;
            }
            printAllElementsAtDepthKUsingRecursionHelper(childans,k,a+1);
        }
    }
public:
    int countLeafNodes() const{
        if(!root){
            throw "The tree is empty";
        }
        int b=0;
        countLeafNodesHelper(root,b);
        return b;
    }

private:
    static int countLeafNodesHelper(GTNode<T> * curr, int & b){
        if(curr->children.size()==0){
            return 1;
        }
        for(int i=0;i<curr->children.size();i++){
            int a = countLeafNodesHelper(curr->children[i],b);
            if(a==1){
                b++;
                continue;
            }
        }
        return 0;
    }
public:
    const GTNode<T> * findSecondLargest() const{
        if(root==NULL){
            throw "The tree is empty";
        }
        pair<GTNode<T> *,GTNode<T> *> P = findSecondLargestNodeHelper(root);
        return P.second;
    }
private:
    static pair<GTNode<T> *, GTNode<T> *> findSecondLargestNodeHelper(GTNode<T> * curr){
        pair<GTNode<T> *,GTNode<T> * > ans(curr,0),childans;
        for(int i=0;i<curr->children.size();i++){
            childans = findSecondLargestNodeHelper(curr->children[i]);
            if(childans.first->data > ans.first->data){
                if(childans.second == NULL || ans.first->data > childans.second -> data){
                    ans.second = ans.first;
                }
                else{
                    ans.second = childans.second;
                }
                ans.first = childans.first;
            }
            else{
                ans.second = childans.second;
            }
        }
        return ans;
    }
public:
    bool operator==(const GenericTree & U) const{
        if(root==NULL||U.root==NULL){
            throw "One of the tree is empty";
        }
        bool b = true;
        return treeEqualityHelper(root,U.root,b);
    }
private:
    static bool treeEqualityHelper(GTNode<T> * curr, GTNode<T> * othercurr,bool b){
        if(curr->data!=othercurr->data || curr->children.size()!=curr->children.size()){
            return false;
        }
        for(int i=0;i<curr->children.size();i++){
            b = treeEqualityHelper(curr->children[i],othercurr->children[i],b);
            if(b==false){
                break;
            }
        }
        return b;
    }
public:
    int countNodesWithDataGreaterThanRoot() const{
        if(!root){
            throw "The tree is empty";
        }
        int b = 0;
        cout<<countNodesWithDataGreaterThanRootHelper(root,root->data,b);
        return b;
    }
private:
    static int countNodesWithDataGreaterThanRootHelper(const GTNode<T> * curr, const T & d, int & b){
        if(curr->data > d){
            b++;
        }
        for (int i=0;i<curr->children.size();i++){
            GTNode<T> * child = curr->children[i];
            countNodesWithDataGreaterThanRootHelper(child,d,b);
        }
    }
public:
    const GTNode<T> * findSpecialNode(){
        if(!root){
            throw "The tree is empty";
        }
        GTNode<T> * test = findSpeicalNodeHelper(root);
        cout<<test->data;
    }
private:
    static GTNode<T> * findSpecialNodeHelper(GTNode<T> * curr){
        pair<GTNode<T> *, T> P(curr,curr->data);
        for(int i=0;i<curr->children.size();i++){
            GTNode<T> * childans = curr->children[i];
            if(childans->children.size()==0){
                if(childans->data>P.second){
                    P.first = childans;
                    P.second = childans->data;
                }
            }
            else{
                T d = childans->data;
                for(int i=0;i<childans->children.size();i++){
                    d += childans->children[i]->data;
                }
                if(d>P.second){
                    P.first = childans;
                    P.second = d;
                }
            }    
        }
        return P.first; 
    }
public:
    const GTNode<T> * findJustLargerThanK(const T & K) const{
        if(!root){
            throw "Tree does not exist";
        }
        
    }
};


#endif