#include"practice_generic.h"
#include <iostream>
using namespace std;
int main(){
	GenericTree<int> T;
	T.createTree();
	cout<<T.countLeafNodes();
	return 0;
}