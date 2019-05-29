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
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int len = A.size();
        int res = 0;
        for (int i = len - 1; i >= 2; i--) {
            if (A[i - 2] + A[i - 1] > A[i]) {
                for (int j = 0; j < 3; ++j) {
                    res += A[i - j];
                }
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}