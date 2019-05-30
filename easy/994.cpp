#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int dirs[4][2] = {{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}};

    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int left = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push(pair<int, int>(i, j));
                } else if (grid[i][j] == 1) {
                    left++;
                }
            }
        }
        if (!left) {
            return 0;
        }
        int count = 0;
        while (!q.empty()) {
            if (!left) {
                return count;
            }
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> p = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = p.first + dirs[j][0];
                    int ny = p.second + dirs[j][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        q.push(pair<int, int>(nx, ny));
                        left--;
                        grid[nx][ny] = 2;
                    }
                }
            }
            count++;
        }
        return left ? -1 : left;
    }
};

int main() {
    Solution solution;
    return 0;
}