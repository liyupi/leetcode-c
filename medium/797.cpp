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
    vector<vector<int>> res;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<int> v;
        dfs(graph, v, 0);
        return res;
    }

    void dfs(vector<vector<int>> &graph, vector<int> &v, int node) {
        int size = graph[node].size();
        v.push_back(node);
        if (!size) {
            res.push_back(vector<int>(v));
            v.pop_back();
            return;
        }
        for (int i = 0; i < size; ++i) {
            dfs(graph, v, graph[node][i]);
        }
        v.pop_back();
    }
};


int main() {
    return 0;
}