#include<iostream>
#include<cstring>
using namespace std;
void printAllCombinations(char * sol, char * nums) {
    if (*nums == '\0') {
        cout << sol << endl;
        return;
    }
    int len = strlen(sol);
    sol[len] = nums[0] - '0' + 'A';
    sol[len+1] = '\0';
    printAllCombinations(sol, nums+1);
    if (nums[1] != '\0') {
        int x = (nums[0] - '0') * 10 + nums[1] - '0';
        if (x <=25) {
            sol[len] = x + 'A';
            sol[len+1] = '\0';
            printAllCombinations(sol, nums + 2);
        }
    }
    return;
}
int main() {
    char sol[100], nums[100];
    cin.getline(nums, 100);
    sol[0] = '\0';
    printAllCombinations(sol, nums);
    return 0;
}
