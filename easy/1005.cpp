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
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int size = A.size();
        int sum = 0;
        int maxNeg = 0;
        for (int i = 0; i < size; ++i) {
            if (K) {
                if (A[i] < 0) {
                    maxNeg = A[i];
                    A[i] = -A[i];
                    K--;
                } else {
                    if (K % 2) {
                        if (maxNeg && -A[i] < maxNeg) {
                            sum += 2 * maxNeg;
                        } else {
                            A[i] = -A[i];
                        }
                    }
                    K = 0;
                }
            }
            sum += A[i];
        }
        return sum;
    }
};

int main() {
    Solution solution;
    return 0;
}