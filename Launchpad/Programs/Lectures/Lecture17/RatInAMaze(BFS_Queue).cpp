#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int x,y,d;
};

bool CanRatEatCheese(int mat[][100],int n,int m,int destx,int desty,int currx,int curry)
{
    queue<Node> Q;
    Node temp = {currx,curry,1};
    Q.push(temp);
    int newx,newy,dis;
    mat[currx][curry]=1;
    int delta[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    while(Q.empty() && (Q.front().x!=destx || Q.front().y!=desty ))
    {
        dis = Q.front().d;
        currx = Q.front().x;
        curry = Q.front().y;
        for(int i = 0;i<4;i++)
        {
            newx = currx + delta[i][0];
            newy = curry + delta[i][1];
            if(newx>=0&&newx<n&&newy>=0&&newy<m)
            {
                mat[newx][newy]=dis + 1;
                Node temp2 = {newx,newy,dis+1};
                Q.push(temp2);
            }
        }
        Q.pop();
    }
    if(Q.empty())
        return false;
    else
    {
        cout<<"The Minimum Distance is : "<<Q.front().d-1<<endl;
        int delta[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        int newx,newy,dis;
        currx = Q.front().x;
        curry = Q.front().y;
        dis = mat[currx][curry];
        while(dis>1)
        {
            for(int i=0;i<4;i++)
            {
                 newx = currx + delta[i][0];
                 newy = curry + delta[i][1];
                 if(mat[newx][newy]==dis-1)
                 {
                     cout<<newx<<' '<<newy<<endl;
                     dis = dis-1;
                     currx = newx;
                     curry = newy;
                     break;
                 }
            }
        }
    }
}


int main()
{


    return 0;
}
