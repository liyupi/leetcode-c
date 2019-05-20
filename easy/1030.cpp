#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:

    class Pos {
    public:
        int x;
        int y;
        int dis;

        Pos(int x, int y, int dis) : x(x), y(y), dis(dis) {

        }
    };

    static bool cmp(const Pos &a, const Pos &b) {
        return a.dis < b.dis;
    }

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<Pos> poses;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                Pos pos(i, j, abs(i - r0) + abs(j - c0));
                poses.push_back(pos);
            }
        }
        sort(poses.begin(), poses.end(), cmp);
        for (int i = 0; i < poses.size(); ++i) {
            vector<int> num;
            num.push_back(poses[i].x);
            num.push_back(poses[i].y);
            res.push_back(num);
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}