#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] - a[1] < b[0] - b[1];
    }

    /**
     * 代价的差值越小越好
     * @param costs
     * @return
     */
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp);
        int sum = 0;
        int num = costs.size() / 2;
        for (int i = 0; i < num; ++i) {
            sum += costs[i][0];
        }
        for (int i = num; i < costs.size(); ++i) {
            sum += costs[i][1];
        }
        return sum;
    }
};

int main() {
    Solution solution;
    return 0;
}