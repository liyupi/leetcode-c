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

using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<vector<string>> res = {{},
                                      {"0",  "1",  "8"},
                                      {"11", "69", "88", "96"}};
        if (n <= 2) {
            return res[n];
        }
        int len1 = res[1].size();
        int len2 = res[2].size() + 1;
        for (int i = 3; i <= n; ++i) {
            vector<string> strs;
            if (i & 1) {
                int size = res[i - 1].size();
                int mid = (i - 1) / 2;
                for (int j = 0; j < size; ++j) {
                    for (int k = 0; k < len1; ++k) {
                        string tmp = res[i - 1][j];
                        tmp.insert(mid, res[1][k]);
                        strs.push_back(tmp);
                    }
                }
            } else {
                int size = res[i - 2].size();
                int mid = (i - 2) / 2;
                if (i == 4) {
                    size--;
                }
                for (int j = 0; j < size; ++j) {
                    for (int k = 0; k < len2; ++k) {
                        string tmp = res[i - 2][j];
                        tmp.insert(mid, res[2][k]);
                        strs.push_back(tmp);
                    }
                }
            }
            if (i == 3) {
                res[2].push_back("00");
            }
            res.push_back(strs);
        }
        return res[n];
    }
};

int main() {
    Solution solution;
    solution.findStrobogrammatic(5);
    return 0;
}