#include<iostream>
#include "unordered_map.h"
using namespace std;

int main()
{
    unorderedMap<int,int> M;
    M.InsertOrUpdate(1,1);
    M.InsertOrUpdate(2,2);
    cout<<M.get(2);
}
