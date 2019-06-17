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
#include <ctime>

using namespace std;

class Solution {
public:
    map<int, vector<int>> mmap;

    Solution(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            mmap[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        return mmap[target][rand() % mmap[target].size()];
    }
};

int main() {
    return 0;
}