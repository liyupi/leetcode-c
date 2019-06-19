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
    double minAreaFreeRect(vector<vector<int>> &points) {
        double res = 0xfffffff;
        int n = points.size();
        if (n < 4) {
            return res;
        }
        set<vector<int>> mset;
        for (int i = 0; i < n; ++i) {
            mset.insert(points[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    long long dis1 = getDis(points[i], points[j]);
                    long long dis2 = getDis(points[j], points[k]);
                    long long dis3 = getDis(points[k], points[i]);
                    int x, y;
                    if (dis1 + dis2 == dis3) {
                        x = points[j][0] + points[k][0] - points[j][0] + points[i][0] - points[j][0];
                        y = points[j][1] + points[k][1] - points[j][1] + points[i][1] - points[j][1];
                        vector<int> v = {x, y};
                        if (mset.count(v)) {
                            res = min(res, sqrt(dis1 * dis2));
                        }
                    }
                    if (dis1 + dis3 == dis2) {
                        x = points[i][0] + points[k][0] - points[i][0] + points[j][0] - points[i][0];
                        y = points[i][1] + points[k][1] - points[i][1] + points[j][1] - points[i][1];
                        vector<int> v = {x, y};
                        if (mset.count(v)) {
                            res = min(res, sqrt(dis1 * dis3));
                        }
                    }
                    if (dis2 + dis3 == dis1) {
                        x = points[k][0] + points[i][0] - points[k][0] + points[j][0] - points[k][0];
                        y = points[k][1] + points[i][1] - points[k][1] + points[j][1] - points[k][1];
                        vector<int> v = {x, y};
                        if (mset.count(v)) {
                            res = min(res, sqrt(dis2 * dis3));
                        }
                    }
                }
            }
        }
        return res == 0xfffffff ? 0 : res;
    }

    long long getDis(vector<int> &points1, vector<int> &points2) {
        return (long long) (points1[0] - points2[0]) * (points1[0] - points2[0]) +
               (long long) (points1[1] - points2[1]) * (points1[1] - points2[1]);
    }

};

int main() {
    Solution solution;
    vector<vector<int>> points = {{3, 1},
                                  {1, 1},
                                  {0, 1},
                                  {2, 1},
                                  {3, 3},
                                  {3, 2},
                                  {0, 2},
                                  {2, 3}};
    solution.minAreaFreeRect(points);
    return 0;
}