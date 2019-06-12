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
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B) {
        int m = A.size();
        int n = B.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < m && j < n) {
            if (A[i][1] < B[j][0]) {
                i++;
                continue;
            }
            if (B[j][1] < A[i][0]) {
                j++;
                continue;
            }
            vector<int> tmp = {max(A[i][0], B[j][0]), min(A[i][1], B[j][1])};
            res.push_back(tmp);
            if (A[i][1] < B[j][1]) {
                i++;
            } else if (B[j][1] < A[i][1]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}