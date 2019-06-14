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
    int longestLine(vector<vector<int>> &M) {
        int m = M.size();
        if (!m) {
            return 0;
        }
        int n = M[0].size();
        int dp[m + 2][n + 2][4];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j]) {
                    dp[i + 1][j + 2][0] = dp[i + 1][j + 1][0] + 1;
                    dp[i + 2][j + 1][1] = dp[i + 1][j + 1][1] + 1;
                    dp[i + 2][j + 2][2] = dp[i + 1][j + 1][2] + 1;
                    dp[i + 2][j][3] = dp[i + 1][j + 1][3] + 1;
                    res = max(res, max(dp[i + 1][j + 2][0],
                                       max(dp[i + 2][j + 1][1], max(dp[i + 2][j + 2][2], dp[i + 2][j][3]))));
                } else {
                    dp[i + 1][j + 2][0] = dp[i + 2][j + 1][1] = dp[i + 2][j + 2][2] = dp[i + 2][j][3] = 0;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> v = {{0,1,1,0},
    {0,1,1,0},
    {0,0,0,1}};
    solution.longestLine(v);
    return 0;
}