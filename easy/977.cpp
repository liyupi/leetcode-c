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
    vector<int> sortedSquares(vector<int> &A) {
        int len = A.size();
        int pos = -1;
        for (int i = 0; i < len; ++i) {
            if (A[i] < 0) {
                pos++;
            }
            A[i] *= A[i];
        }
        int left = pos;
        int right = pos + 1;
        vector<int> res;
        while(left >= 0 && right < len) {
            if (A[left] < A[right]) {
                res.push_back(A[left--]);
            } else {
                res.push_back(A[right++]);
            }
        }
        while(left >= 0) {
            res.push_back(A[left--]);
        }
        while(right < len) {
            res.push_back(A[right++]);
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}