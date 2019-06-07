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
    bool visited[10];
    set<int> mset = {13, 46, 79, 17, 28, 39, 19, 37, 31, 64, 97, 71, 82, 93, 91, 73};

    int numberOfPatterns(int m, int n) {
        memset(visited, false, sizeof(visited));
        dfs(m, n, 0, 0);
        return res;
    }

    void dfs(int m, int n, int len, int num) {
        if (len == n) {
            res++;
            return;
        }
        if (len >= m) {
            res++;
        }
        for (int i = 1; i <= 9; ++i) {
            if (!visited[i] && (!mset.count(num * 10 + i) || visited[(num + i) / 2])) {
                visited[i] = true;
                dfs(m, n, len + 1, i);
                visited[i] = false;
            }
        }
    }

};

int main() {
    return 0;
}