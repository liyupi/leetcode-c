#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>> &board) {
        int res = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') {
                    res++;
                    if (i != m - 1 && board[i + 1][j] == 'X') {
                        res--;
                    }
                    if (j != n - 1 && board[i][j + 1] == 'X') {
                        res--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> v = {{'X', '.', '.', 'X'},
                              {'.', '.', '.', 'X'},
                              {'.', '.', '.', 'X'}};
    solution.countBattleships(v);
    return 0;
}