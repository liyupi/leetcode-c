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

class UnionSet {
public:
    vector<int> parent;

    UnionSet(int n) {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }
    }

    int find(int num) {
        while (parent[num] != num) {
            num = find(parent[num]);
        }
        return num;
    }

    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        parent[a] = b;
    }

    int count() {
        int sum = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i) {
                sum++;
            }
        }
        return sum;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();
        UnionSet unionSet(4 * n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int start = 4 * (i * n + j);
                switch (grid[i][j]) {
                    case '/':
                        unionSet.merge(start, start + 3);
                        unionSet.merge(start + 1, start + 2);
                        break;
                    case '\\':
                        unionSet.merge(start, start + 1);
                        unionSet.merge(start + 2, start + 3);
                        break;
                    case ' ':
                        unionSet.merge(start, start + 1);
                        unionSet.merge(start + 1, start + 2);
                        unionSet.merge(start + 2, start + 3);
                        break;
                }
                if (i > 0) {
                    unionSet.merge(start, start - 4 * n + 2);
                }
                if (j > 0) {
                    unionSet.merge(start + 3, start - 3);
                }
            }
        }
        return unionSet.count();
    }

};


int main() {
    Solution solution;
    return 0;
}