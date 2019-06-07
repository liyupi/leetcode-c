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
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            bool flag = !A[i][0];
            for (int j = 0; j < n; ++j) {
                if (flag) {
                    A[i][j] = 1 - A[i][j];
                }
                if (A[i][j] == 1) {
                    v[j]++;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            v[j] = max(v[j], m - v[j]);
            sum = sum * 2 + v[j];
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> v = {{1,1,1,1},{1,0,0,1},{1,1,1,1}};
    solution.matrixScore(v);
    return 0;
}