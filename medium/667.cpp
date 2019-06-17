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
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int left = 1;
        int right = n;
        int num = 0;
        while (num++ < k) {
            res.push_back(num & 1 ? left++ : right--);
        }
        if (k & 1) {
            for (int i = left; i <= right; ++i) {
                res.push_back(i);
            }
        } else {
            for (int i = right; i >= left; --i) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}