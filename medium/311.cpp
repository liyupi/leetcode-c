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
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ma = A.size();
        int na = A[0].size();
        int mb = B.size();
        int nb = B[0].size();
        vector<vector<int>> res(ma);
        for (int i = 0; i < ma; ++i) {
            for (int j = 0; j < nb; ++j) {
                int sum = 0;
                for (int k = 0; k < na; ++k) {
                    sum += A[i][k] * B[k][j];
                }
                res[i].push_back(sum);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}