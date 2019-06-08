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
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((right - mid) & 1) {
                if (nums[mid] != nums[mid + 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (nums[mid] != nums[mid + 1]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return nums[left];
    }
};

int main() {
    return 0;
}