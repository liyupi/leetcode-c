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
    vector<int> numMovesStones(int a, int b, int c) {
        int nums[] = {a, b, c};
        sort(nums, nums + 3);
        vector<int> res;
        int min = 0;
        if (nums[0] < nums[1] - 1) {
            min++;
        }
        if (nums[2] > nums[1] + 1) {
            min++;
        }
        if (nums[2] - nums[1] == 2 || nums[1] - nums[0] == 2) {
            min = 1;
        }
        int max = nums[2] - nums[0] - 2;
        res.push_back(min);
        res.push_back(max);
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}