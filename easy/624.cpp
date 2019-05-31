#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &arrays) {
        int size = arrays.size();
        int minNum = 100000;
        int nextMin = minNum;
        int maxNum = -100000;
        int nextMax = maxNum;
        int minPos = -1, maxPos = -1;
        for (int i = 0; i < size; ++i) {
            if (arrays[i][0] <= minNum) {
                minPos = i;
                nextMin = minNum;
                minNum = arrays[i][0];
            } else if (arrays[i][0] <= nextMin) {
                nextMin = arrays[i][0];
            }
            if (arrays[i][arrays[i].size() - 1] >= maxNum) {
                maxPos = i;
                nextMax = maxNum;
                maxNum = arrays[i][arrays[i].size() - 1];
            } else if (arrays[i][arrays[i].size() - 1] >= nextMax) {
                nextMax = arrays[i][arrays[i].size() - 1];
            }
        }
        if (minPos == maxPos) {
            return max(maxNum - nextMin, nextMax - minNum);
        }
        return maxNum - minNum;
    }
};

int main() {
    return 0;
}