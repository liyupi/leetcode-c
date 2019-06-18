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
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return to_string(nums[0]);
        }
        if (n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        stringstream ss;
        ss << nums[0] << "/(" << nums[1];
        for (int i = 2; i < n; ++i) {
            ss <<  "/" << nums[i];
        }
        ss << ")";
        return ss.str();
    }
};

int main() {
    return 0;
}