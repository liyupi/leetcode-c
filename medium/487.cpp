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
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int dp1 = 0;
        int dp0 = 0;
        int res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                dp1 = dp1 + 1;
                dp0 = dp0 + 1;
            } else {
                dp1 = dp0 + 1;
                dp0 = 0;
            }
            res = max(dp1, max(res, dp0));
        }
        return res;
    }
};

int main() {
    return 0;
}