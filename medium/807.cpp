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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<int> top(m);
        vector<int> left(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                top[i] = max(grid[i][j], top[i]);
                left[j] = max(grid[i][j], left[j]);
            }
        }
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                sum += min(top[i], left[j]) - grid[i][j];
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}