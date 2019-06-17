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
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B) {
        int n = A.size();
        int res = -1;
        // 向下循环移动
        for (int k = -n + 1; k < n; ++k) {
            // 向右循环移动
            for (int l = -n + 1; l < n; ++l) {
                int count = 0;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int val;
                        if (i >= k && j >= l && i - k < n && j - l < n) {
                            val = A[i - k][j - l];
                        } else {
                            val = 0;
                        }
                        count += val * B[i][j];
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> v1 = {{1, 1, 0},
                              {0, 1, 0},
                              {0, 1, 0}};
    vector<vector<int>> v2 = {{0, 0, 0},
                              {0, 1, 1},
                              {0, 0, 1}};
    solution.largestOverlap(v1, v2);
    return 0;
}