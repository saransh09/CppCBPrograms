#include<iostream>
using namespace std;
int minCoins(int S, int *denom, int denomsize) {
    if (S <= 0) {
        return -1;
    }
    for (int i = 0; i < denomsize; i++) {
        if (denom[i] == S) {
            return 1;
        }
    }
    int ans = -1;
    for (int i = 0; i < denomsize; i++) {
        int subans = minCoins(S-denom[i], denom, denomsize);
        if (subans!= -1) {
            if (ans == -1 || ans > subans) {
                ans = subans;
            }
        }
    }
    if ( ans == -1) { 
        return ans;
    } else {
        return ans+1;
    }
}
int main() {
    minCoins(50,[],5);
    return 0;
}
