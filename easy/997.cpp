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
    int findJudge(int N, vector<vector<int>>& trust) {
        int trustNum[N + 1];
        memset(trustNum, 0, sizeof(trustNum));
        int size = trust.size();
        for (int i = 0; i < size; ++i) {
            trustNum[trust[i][0]]--;
            trustNum[trust[i][1]]++;
        }
        for (int i = 1; i <= N; ++i) {
            if (trustNum[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    return 0;
}