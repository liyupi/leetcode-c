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
    vector<int> singleNumber(vector<int>& nums) {
        int val = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            val ^= nums[i];
        }
        int mask = val & (-val);
        int ans[2];
        ans[0] = ans[1] = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] & mask) {
                ans[1] ^= nums[i];
            } else {
                ans[0] ^= nums[i];
            }
        }
        vector<int> res;
        res.push_back(ans[0]);
        res.push_back(ans[1]);
        return res;
    }
};

int main() {
    return 0;
}