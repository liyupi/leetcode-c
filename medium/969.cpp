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
    vector<int> pancakeSort(vector<int> &A) {
        vector<int> res;
        int n = A.size() - 1;
        for (int i = 0; i < n; ++i) {
            // 找到最大的值
            int maxNum = A[0];
            int pos = 0;
            for (int j = 1; j < A.size() - i; ++j) {
                if (maxNum < A[j]) {
                    pos = j;
                    maxNum = A[j];
                }
            }
            int left = 0;
            int right = pos;
            res.push_back(right + 1);
            while (left < right) {
                swap(A[left++], A[right--]);
            }
            left = 0;
            right = A.size() - i - 1;
            res.push_back(right + 1);
            while (left < right) {
                swap(A[left++], A[right--]);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> a = {3,2,4,1};
    solution.pancakeSort(a);
    return 0;
}