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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[abs(nums[i]) - 1] < 0) {
                res.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return res;
    }

/*    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int pos = 0;
        int n = nums.size();
        while(pos < n) {
            if (nums[pos] - 1 == pos || nums[pos] == nums[nums[pos] - 1]) {
                pos++;
            } else {
                swap(nums[pos], nums[nums[pos] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != nums[i] - 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }*/
};

int main() {
    Solution solution;
    vector<int> v = {4,3,2,7,8,2,3,1};
    solution.findDuplicates(v);
    return 0;
}