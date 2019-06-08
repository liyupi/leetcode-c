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
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        if (!m) {
            return 0;
        }
        int n = picture[0].size();
        int row[m];
        int col[n];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                   row[i]++;
                   col[j]++;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    sum++;
                }
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}