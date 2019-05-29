#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp(heights);
        sort(tmp.begin(), tmp.end());
        int res = 0;
        int len = heights.size();
        for (int i = 0; i < len; ++i) {
            if (heights[i] != tmp[i]) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}