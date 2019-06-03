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

using namespace std;

/**
 * 并查集
 * 每条边都应该能使2个点合并，否则会出现孤立的点
 * 若联通，最后所有点应合并成一个集
 * https://blog.csdn.net/qq508618087/article/details/50809058
 */
class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        int size = edges.size();
        if (n != size + 1) {
            return false;
        }
        int parent[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < size; ++i) {
            int x = edges[i][0], y = edges[i][1];
            while(x != parent[x]) {
                x = parent[x];
            }
            while(y != parent[y]) {
                y = parent[y];
            }
            if (x != y) {
                parent[y] = x;
                // 每合并一次，少一个集
                n--;
            }
        }
        // 判断是否所有点处于一个集
        return n == 1;
    }
};

int main() {
    return 0;
}