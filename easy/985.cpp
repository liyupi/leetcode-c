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
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries) {
        int sum = 0;
        int size = A.size();
        for (int i = 0; i < size; ++i) {
            if (!(A[i] & 1)) {
                sum += A[i];
            }
        }
        size = queries.size();
        vector<int> res;
        for (int i = 0; i < size; ++i) {
            int tmp = A[queries[i][1]];
            int bOdd = tmp & 1;
            A[queries[i][1]] += queries[i][0];
            int num = A[queries[i][1]];
            int nOdd = num & 1;
            if (!bOdd) {
                sum -= tmp;
            }
            if (!nOdd) {
                sum += num;
            }
            res.push_back(sum);
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}