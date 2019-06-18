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
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != mid) {
                res += abs(nums[i] - nums[mid]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}