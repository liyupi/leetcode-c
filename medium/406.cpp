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
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        int n = people.size();
        vector<vector<int>> res(n);
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < n; ++i) {
            int num = people[i][1];
            int j = 0;
            while (true) {
                if (res[j].size()) {
                    num++;
                }
                if (!num) {
                    break;
                }
                j++;
                num--;
            }
            res[j] = people[i];
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> v = {{7, 0},
                             {4, 4},
                             {7, 1},
                             {5, 0},
                             {6, 1},
                             {5, 2}};
    solution.reconstructQueue(v);
    return 0;
}