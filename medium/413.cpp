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
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int len = A.size() - 2;
        for (int i = 0; i < len; ++i) {
            int j = i;
            int d = A[i + 1] - A[i];
            while (i + 2 < A.size() && d == A[i + 2] - A[i + 1]) {
                i++;
            }
            if (i - j) {
                res += getVal(i + 2 - j);
                i++;
            }
        }
        return res;
    }

    int getVal(int n) {
        int sum = 0;
        for (int i = 2; i <= n; ++i) {
            sum += n - i;
        }
        return sum;
    }

};

int main() {
    Solution solution;
    vector<int> v;
    solution.numberOfArithmeticSlices(v);
    return 0;
}