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
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += A[i];
        }
        if (sum % 3) {
            return false;
        }
        int goal = sum / 3;
        int left = -1;
        sum = 0;
        for (int i = 0; i < size - 1; ++i) {
            sum += A[i];
            if (left == -1 && sum == goal) {
                left = i;
                sum = 0;
            }
            if (left != -1 && sum == goal) {
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