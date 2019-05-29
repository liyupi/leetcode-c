#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int> &A) {
        int size = A.size();
        int leftSum[size];
        leftSum[0] = A[0];
        for (int i = 1; i < size; ++i) {
            leftSum[i] = leftSum[i - 1] + A[i];
        }
        if (leftSum[size - 1] % 3) {
            return false;
        }
        int goal = leftSum[size - 1] / 3;
        int left = -1, right = -1;
        for (int i = 0; i < size - 1; ++i) {
            if (left == -1 && leftSum[i] == goal) {
                left = i;
            }
            if (left != -1 && leftSum[i] == 2 * goal) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    int nums[] = {0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1};
    vector<int> a(nums, nums + 11);
    solution.canThreePartsEqualSum(a);

    return 0;
}