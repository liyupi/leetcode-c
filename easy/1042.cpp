#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * 思路：记下每个点邻接的点，然后从1开始遍历每个点，选一个其临接点未染的颜色
     * @param N
     * @param paths
     * @return
     */
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
        vector<int> res(N, 0);
        map<int, set<int>> mmap;
        for (int i = 0; i < paths.size(); ++i) {
            mmap[paths[i][0]].insert(paths[i][1]);
            mmap[paths[i][1]].insert(paths[i][0]);
        }
        for (int i = 1; i <= N; ++i) {
            set<int> used;
            for (set<int>::iterator it = mmap[i].begin(); it != mmap[i].end(); ++it) {
                if (res[*it - 1] != 0) {
                    used.insert(res[*it - 1]);
                }
            }
            for (int j = 1; j <= 4; ++j) {
                if (used.find(j) == used.end()) {
                    res[i - 1] = j;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}