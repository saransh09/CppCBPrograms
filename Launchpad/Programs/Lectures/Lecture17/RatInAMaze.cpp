#include<iostream>
#include<stack>
using namespace std;

struct node
{
    int x,y,dir;
};

bool canRatEatCheese(int mat[][100],int N,int M,int destx,int desty,int currx,int curry)
{
    stack<node> S;
    int newx,newy;
    node el = {currx, curry, 0};
    S.push(el);
    mat[currx][curry]=2;
    int delta[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!S.empty() && (S.top().x != destx || S.top().y != desty))
    {
        int i = S.top().dir;
        currx = S.top().x;
        curry = S.top().y;
        for(;i<4;i++)
        {
            newx = currx + delta[i][0];
            newy = curry + delta[0][i];
            if(newx>=0 && newx<N && newy>=0 && newy<M && mat[newx][newy]==0)
            {
                S.top().dir = i+1;
                node temp = {newx,newy,0};
                S.push(temp);
                mat[newx][newy] = 2;
                break;
            }
        }
        if(i==4)
        {
            mat[S.top().x][S.top().y]=1;
            S.pop();
        }
    }
    if(S.empty())
    {
        return false;
    }

    else
    {
        while(!S.empty())
        {
            cout<<S.top().x<<','<<S.top().y<<' ';
            S.pop();
        }
        cout<<endl;
        return true;
    }
}

int main()
{
    int mat[100][100];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mat[i][j]=0;
        }
    }
    int ratx,raty,cheesex,cheesey;
    cin>>ratx>>raty;
    cin>>cheesex>>cheesey;
    if(canRatEatCheese(mat,n,m,cheesex,cheesey,ratx,raty))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}
