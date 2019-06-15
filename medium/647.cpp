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
    int countSubstrings(string s) {
        int len = s.length();
        int dp[len][len];
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = 1;
            res++;
        }
        for (int i = 1; i < len; ++i) {
            if (s[i - 1] == s[i]) {
                dp[i - 1][i] = 1;
                res++;
            } else {
                dp[i - 1][i] = 0;
            }
        }
        for (int j = 2; j < len; ++j) {
            for (int i = 0; i < len - j; ++i) {
                if (dp[i + 1][i +j - 1] && s[i] == s[i + j]) {
                    dp[i][i + j] = 1;
                    res++;
                } else {
                    dp[i][i + j] = 0;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}