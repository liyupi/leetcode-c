#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

/**
 * 摩尔投票法
 * https://blog.csdn.net/magicbean2/article/details/73737526
 */
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> ans;
        int cx = 0, cy = 0, numx = 0, numy = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if ((cx == 0 || numx == nums[i]) && nums[i] != numy) {
                cx++;
                numx = nums[i];
            } else if (cy == 0 || numy == nums[i]) {
                cy++;
                numy = nums[i];
            } else {
                cx--;
                cy--;
            }
        }
        int count = 0;
        for (auto num : nums){
            if (numx == num){
                ++count;
            }
        }
        if (count > nums.size()/3){
            ans.push_back(numx);
        }
        if (numx == numy) {
            return ans;
        }
        count = 0;
        for (auto num : nums){
            if (numy == num){
                ++count;
            }
        }
        if (count > nums.size()/3){
            ans.push_back(numy);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    solution.majorityElement(v);
    return 0;
}