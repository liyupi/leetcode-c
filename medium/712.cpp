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
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int dp[len1 + 1][len2 + 1];
        dp[0][0] = 0;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < len1; ++i) {
            c1 += s1[i];
            dp[i + 1][0] = c1;
        }
        for (int i = 0; i < len2; ++i) {
            c2 += s2[i];
            dp[0][i + 1] = c2;
        }
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    int tmp1 = dp[i][j + 1] + s1[i];
                    int tmp2 = dp[i + 1][j] + s2[j];
                    int tmp3 = dp[i][j] + s1[i] + s2[j];
                    dp[i + 1][j + 1] = min(tmp1, min(tmp2, tmp3));
                }
            }
        }
        return dp[len1][len2];
    }
};

int main() {
    Solution solution;
    return 0;
}