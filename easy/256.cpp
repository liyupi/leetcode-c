#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        int dp[size + 1][3];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= size; ++i) {
            dp[i][0] = min(dp[i - 1][1],dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0],dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][0],dp[i - 1][1]) + costs[i - 1][2];
        }
        return min(min(dp[size][0], dp[size][1]), dp[size][2]);
    }
};

int main() {
    Solution solution;
    return 0;
}