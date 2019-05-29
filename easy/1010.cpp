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
    int numPairsDivisibleBy60(vector<int> &time) {
        int size = time.size();
        int nums[60] = {0};
        int res = 0;
        for (int i = 0; i < size; ++i) {
            int tmp = time[i] % 60;
            res += nums[(60 - tmp) % 60];
            nums[tmp]++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}