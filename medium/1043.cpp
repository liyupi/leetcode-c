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

class Solution {
public:
    map<int, int> mmap;

    int maxSumAfterPartitioning(vector<int>& A, int K) {
        return maxSumAfterPartitioning(A, K, 0);
    }

    int maxSumAfterPartitioning(vector<int>& A, int K, int pos) {
        if (pos >= A.size()) {
            return 0;
        }
        if (mmap[pos]) {
            return mmap[pos];
        }
        int res = 0;
        int maxNum = -1;
        for (int i = 1; i <= K; ++i) {
            if (pos + i - 1 >= A.size()) {
                break;
            }
            maxNum = max(A[pos + i - 1], maxNum);
            int tmp = maxNum * i + maxSumAfterPartitioning(A, K, pos + i);
            res = max(res, tmp);
        }
        mmap[pos] = res;
        return res;
    }
};

int main() {
    return 0;
}