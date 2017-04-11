#ifndef GRAPHS_H
#define GRAPHS_H
#include<vector>
#include<queue>
#include<list>                                 //list of STL is doubly linked list
#include<iostream>
using namespace std;
class Graph      //Doing for undirected graphs
{
    vector<list<int> > adjList;                 //If weighted graphs were to be created, list of pairs would have done the job
public:
    Graph() {}

    int V() const
    {
        return adjList.size();
    }

    void addEdge(int src,int dest)              //count of vertices is not necessary
    {
        int max = src > dest ? src : dest;
        if(max+1 > V() )
        {
            adjList.resize(max + 1);
        }
        list<int>::iterator it = adjList[src].begin();
        while(it!=adjList[src].end())
        {
            if(it != adjList[src].end())
            {
                throw "You are inserting this edge again";
            }
            it++;
        }
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void BFS()
    {
        vector<bool> visited(V(),false);
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==true)
            {
                continue;
            }
            queue<int> Q;
            Q.push(i);
            visited[i]=true;
            while(!Q.empty())
            {
                int current = Q.front();
                Q.pop();
                cout<<current <<' ';
                list<int>::iterator it = adjList[current].begin();
                while(it != adjList[current].end())
                {
                    if(visited[*it] == false)
                    {
                        Q.push(*it);
                        visited[*it] = true;
                    }
                    it++;
                }
            }
        }
    }

    void DFS()
    {
        vector<bool> visited(V(),false);
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==true)
            {
                continue;
            }
            DFSUtil(i,visited);
        }
    }

    void DFSUtil(int src,vector<bool> & visited)                           //driver function which performs dfs for each input source
    {
        visited[src]=true;
        cout<<src<<' ';
        list<int>::iterator it = adjList[src].begin();
        while(it != adjList[src].end())
        {
            if(visited[*it] == false)
            {
                DFSUtil(*it,visited);
            }
            it++;
        }
    }

    vector<int> returnShortestPath(int src,int dest)
    {
        vector<int> visitedVertices(V(),-1);

    }

    vector<vector<int> > returnConnectedGraphsHelper()
    {
        vector<bool> visited(V(),false);
        vector<vector<int> > master;
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==true)
            {
                continue;
            }
            queue<int> Q;
            Q.push(i);
            visited[i]=true;
            vector<int> temp;
            while(!Q.empty())
            {
                int current = Q.front();
                Q.pop();
                temp.push_back(current)
                list<int>::iterator it = adjList[current].begin();
                while(it != adjList[current].end())
                {
                    if(visited[*it] == false)
                    {
                        Q.push(*it);
                        visited[*it] = true;
                    }
                    it++;
                }
            }
            master.push_back(temp);
        }
        return master;
    }

    void returnConnectedGraphs()
    {
        vector<vector<int> > V = returnConnectedGraphsHelper();
        for(int i=0;i<V.size();i++)
        {
            for(int j=0;j<V[i].size();j++)
            {
                //cout<<V[]
            }
        }
    }
};
#endif // GRAPHS_H
