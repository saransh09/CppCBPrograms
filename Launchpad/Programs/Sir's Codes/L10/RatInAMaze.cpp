#include<iostream>
using namespace std;
bool canRatEatCheese(int mat[][100], int N, int M, int destx, int desty, int currx, int curry) {
    mat[currx][curry] = 2;
    if (currx == destx && curry == desty) {
        return true;
    }
    int newx, newy;
    int delta[4][2] = {{-1,0}, {+1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        newx = currx + delta[i][0];
        newy = curry + delta[i][1];
        if (newx >=0 && newx < N && newy >=0 && newy < M && mat[newx][newy] == 0) {
            bool ans = canRatEatCheese(mat, N, M, destx, desty, newx, newy);
            if (ans) {
                return true;
            }
        }
    }
    mat[currx][curry] = 1;
    return false;
}
int main() {
    int mat[100][100];
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }
    int ratx,raty,cheezex,cheezey;
    cout << "Enter coord of rat " << endl;
    cin >> ratx >> raty;
    cout << "Enter coord of cheeze " << endl;
    cin >> cheezex >> cheezey;
    if (canRatEatCheese(mat,N,M,cheezex, cheezey, ratx, raty)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
