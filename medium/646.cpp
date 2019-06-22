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
#include <ctime>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>a, vector<int>b) {return a[1] < b[1]; });
        int res = 1;
        int right = pairs[0][1];
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > right) {
                right = pairs[i][1];
                res++;
            }
        }
        return res;
    }
/*    int findLongestChain(vector<vector<int>> &pairs) {
        if (pairs.empty()) {
            return 0;
        }
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        int res = -1;
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }*/
};

int main() {
    Solution solution;
    return 0;
}