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
    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        int m = board.size();
        int n = board[0].size();
        int visited[m][n];
        bool flag;
        do {
            flag = true;
            memset(visited, 0, sizeof(visited));
            for (int i = 0; i < m; ++i) {
                int left;
                for (int j = 0; j < n - 2; j = left) {
                    left = j + 1;
                    if (!board[i][left]) {
                        continue;
                    }
                    while (left < n && board[i][left] == board[i][j]) {
                        left++;
                    }
                    if (left - j > 2) {
                        for (int k = j; k < left; ++k) {
                            visited[i][k] = board[i][k];
                            board[i][k] = 0;
                        }
                        flag = false;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                int down;
                for (int i = 0; i < m - 2; i = down) {
                    int tmp = board[i][j];
                    if (visited[i][j]) {
                        tmp = visited[i][j];
                    }
                    down = i + 1;
                    if (!tmp) {
                        continue;
                    }
                    while (down < m) {
                        if (visited[down][j] && visited[down][j] == tmp) {
                            down++;
                        } else if (!visited[down][j] && board[down][j] == tmp) {
                            down++;
                        } else {
                            break;
                        }
                    }
                    if (down - i > 2) {
                        for (int k = i; k < down; ++k) {
                            board[k][j] = 0;
                        }
                        flag = false;
                    }
                }
            }
            for (int j = 0; j < n; ++j) {
                int i = m - 1;
                int pos = m - 1;
                while(i >= 0) {
                    if (board[i][j]) {
                        int tmp = board[i][j];
                        board[i][j] = 0;
                        board[pos--][j] = tmp;
                    }
                    i--;
                }
            }
        } while (!flag);
        return board;
    }
};

int main() {
    vector<vector<int>> v = {{110, 5,   112, 113, 114},
                             {210, 211, 5,   213, 214},
                             {310, 311, 3,   313, 314},
                             {410, 411, 412, 5,   414},
                             {5,   1,   512, 3,   3},
                             {610, 4,   1,   613, 614},
                             {710, 1,   2,   713, 714},
                             {810, 1,   2,   1,   1},
                             {1,   1,   2,   2,   2},
                             {4,   1,   4,   4,   1014}};
    Solution solution;
    solution.candyCrush(v);
    return 0;
}