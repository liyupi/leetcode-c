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
    int sum[2] = {0, 0};
    int total = 0;
    bool stoneGame(vector<int> &piles) {
        return true;
    }
/*    bool stoneGame(vector<int> &piles) {
        for (int i = 0; i < piles.size(); ++i) {
            total += piles[i];
        }
        return dfs(piles, 0, piles.size(), true);
    }

    bool dfs(vector<int> &piles, int left, int right, int turn) {
        if (left == right || sum[0] > total - sum[0]) {
            return sum[0] > sum[1];
        }
        sum[turn] += piles[left];
        if (dfs(piles, left + 1, right, 1 - turn)) {
            return true;
        }
        sum[turn] -= piles[left];
        sum[turn] += piles[right - 1];
        if (dfs(piles, left, right - 1, 1 - turn)) {
            return true;
        }
        sum[turn] -= piles[right - 1];
        return false;
    }*/
};

int main() {
    return 0;
}