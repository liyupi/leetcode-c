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
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int d = abs(target[0]) + abs(target[1]);
        int minD = d + 1;
        for (int i = 0; i < ghosts.size(); ++i) {
            minD = min(minD, abs(target[0] - ghosts[i][0]) + abs(target[1] - ghosts[i][1]));
        }
        return minD > d;
    }
};


int main() {
    return 0;
}