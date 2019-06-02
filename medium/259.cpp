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
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int res = 0;
        for (int k = size - 1; k >= 2; --k) {
            int num = target - nums[k];
            int left = 0;
            int right = k - 1;
            while(left < right) {
                if (nums[left] + nums[right] < num) {
                    res += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}