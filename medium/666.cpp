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
    int res = 0;
    map<int, int> mmap;

    int pathSum(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            mmap[nums[i] / 10] = nums[i] % 10;
        }
        inOrder(nums[0] % 10, nums[0] / 10);
        return res;
    }

    void inOrder(int sum, int rootPos) {
        int leftPos = rootPos - rootPos % 10 + 10 + 2 * (rootPos % 10) - 1;
        int rightPos = leftPos + 1;
        if (!mmap.count(leftPos) && !mmap.count(rightPos)) {
            res += sum;
        }
        if (mmap.count(leftPos)) {
            inOrder(sum + mmap[leftPos], leftPos);
        }
        if (mmap.count(rightPos)) {
            inOrder(sum + mmap[rightPos], rightPos);
        }
    }

};

int main() {
    Solution solution;
    vector<int> v = {111, 217, 221, 315, 415};
    solution.pathSum(v);
    return 0;
}