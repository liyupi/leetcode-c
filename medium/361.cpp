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
    int m, n;

    int maxKilledEnemies(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) {
            return 0;
        }
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    int num = search(grid, i, j);
                    res = max(num, res);
                }
            }
        }
        return res;
    }

    int search(const vector<vector<char>> &grid, int i, int j) {
        int sum = 0;
        // up
        for (int k = i - 1; k >= 0; --k) {
            if (grid[k][j] == 'W') {
                break;
            }
            if (grid[k][j] == 'E') {
                sum++;
            }
        }
        // down
        for (int k = i + 1; k < m; ++k) {
            if (grid[k][j] == 'W') {
                break;
            }
            if (grid[k][j] == 'E') {
                sum++;
            }
        }
        // left
        for (int k = j - 1; k >= 0; --k) {
            if (grid[i][k] == 'W') {
                break;
            }
            if (grid[i][k] == 'E') {
                sum++;
            }
        }
        // right
        for (int k = j + 1; k < n; ++k) {
            if (grid[i][k] == 'W') {
                break;
            }
            if (grid[i][k] == 'E') {
                sum++;
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}