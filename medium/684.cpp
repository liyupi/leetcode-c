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
    vector<int> parents;

    bool unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return false;
        }
        parents[px] = py;
        return true;
    }

    int find(int x) {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            parents.push_back(i);
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        init(n);
        int res = 0;
        for (int i = 0; i < edges.size(); ++i) {
            if (!unionSet(edges[i][0], edges[i][1])) {
                res = i;
            }
        }
        return edges[res];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};
    solution.findRedundantConnection(edges);
    return 0;
}