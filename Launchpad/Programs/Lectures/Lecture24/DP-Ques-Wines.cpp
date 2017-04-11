#include<iostream>
#include<vector>
#include<math.h>
using namespace std;



int getMaxValue(vector<int> price,int s,int e,int y)
{
    if(s==e)
    {
        return price[s]*y;
    }
    return max(getMaxValue(price,s+1,e,y+1)+price[s]*y,getMaxValue(price,s,e-1,y+1)+price[e]*y);
}

int main()
{
    vector<int> price;
    price.push_back(2);
    price.push_back(3);
    price.push_back(5);
    price.push_back(1);
    price.push_back(4);
    cout<<getMaxValue(price,0,4,1);
}
