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
 * https://blog.csdn.net/qq508618087/article/details/50871819
 */
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            if (i & 1) {
                if (nums[i - 1] > nums[i]) {
                    swap(nums[i - 1], nums[i]);
                }
            } else {
                if (nums[i - 1] < nums[i]) {
                    swap(nums[i - 1], nums[i]);
                }
            }
        }
    }
};

int main() {
    return 0;
}