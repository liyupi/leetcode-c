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
    int res = 0;

    int countArrangement(int N) {
        vector<bool> visited(N);
        dfs(1, N, visited);
        return res;
    }

    void dfs(int pos, int N, vector<bool> &visited) {
        if (pos > N) {
            res++;
            return;
        }
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && !(pos % i && i % pos)) {
                visited[i] = true;
                dfs(pos + 1, N, visited);
                visited[i] = false;
            }
        }
    }
};

int main() {
    Solution solution;
    return 0;
}