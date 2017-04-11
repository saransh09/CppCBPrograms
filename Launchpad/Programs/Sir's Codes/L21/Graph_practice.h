##ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
using namespace std;
class Graph{
	vector<list<int> > adjList;
public:
	Graph() {}
	int V() const {
		return adjList.size();
	}
	void addEdge(int src, int dest) {
		int max = src > dest ? src : dest;
		if (max + 1 > V()) {
			adjList.resize(max + 1);
		}
		list<int> iterator it = find(adjList[src].begin(), adjList[src].end(), dest);
		
	}



};





#endif