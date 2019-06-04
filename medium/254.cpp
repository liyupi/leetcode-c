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
    vector<vector<int>> res;

    vector<vector<int>> getFactors(int n) {
        vector<int> v;
        dfs(n, 2, v);
        return res;
    }

    /**
     * 利用start去重
     * @param n
     * @param start
     * @param v
     */
    void dfs(int n, int start, vector<int> &v) {
        int maxNum = sqrt(n);
        for (int i = start; i <= maxNum; ++i) {
            if (n % i == 0) {
                v.push_back(i);
                v.push_back(n / i);
                res.push_back(v);
                v.pop_back();
                dfs(n / i, i, v);
                v.pop_back();
            }
        }
    }
};

int main() {
    return 0;
}