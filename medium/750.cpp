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
    int countCornerRectangles(vector<vector<int>> &grid) {
        int m = grid.size();
        if (!m) {
            return 0;
        }
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int count = 0;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] && grid[j][k]) {
                        count++;
                    }
                }
                res += count * (count - 1) / 2;
            }
        }
        return res;
    }
    /*int countCornerRectangles(vector<vector<int>> &grid) {
        int m = grid.size();
        if (!m) {
            return 0;
        }
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                for (int k = j + 1; k < n; ++k) {
                    if (!grid[i][k]) {
                        continue;
                    }
                    for (int l = i + 1; l < m; ++l) {
                        if (grid[l][j] && grid[l][k]) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }*/
};

int main() {
    return 0;
}