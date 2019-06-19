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

class NumArray {
public:
    vector<int> C;
    vector<int> nums;

    NumArray(vector<int> &nums) : nums(nums) {
        for (int i = 0; i <= nums.size(); ++i) {
            C.push_back(0);
        }
        for (int i = 0; i < nums.size(); ++i) {
            add(i, nums[i]);
        }
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int i, int val) {
        for (int k = i + 1; k <= nums.size(); k += lowbit(k)) {
            C[k] += val;
        }
    }

    void update(int i, int val) {
        int add = val - nums[i];
        nums[i] = val;
        for (int k = i + 1; k <= nums.size(); k += lowbit(k)) {
            C[k] += add;
        }
    }

    int getSum(int i) {
        int sum = 0;
        for (int k = i; k > 0; k -= lowbit(k)) {
            sum += C[k];
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
};

int main() {
    vector<int> v = {1, 3, 5};
    NumArray numArray(v);
    numArray.getSum(3);
    numArray.update(1, 5);
    numArray.sumRange(1, 2);
    return 0;
}