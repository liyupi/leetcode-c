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

    void quickSort(vector<vector<int>> &points, vector<pair<int, int>> &dis, int left, int right, int k) {
        if (k <= 0) {
            return;
        }
        if (left == right) {
            return;
        }
        if (k >= right - left) {
            for (int i = left; i < right; ++i) {
                res.push_back(points[dis[i].first]);
            }
            return;
        }
        int index = left;
        for (int i = left + 1; i < right; ++i) {
            if (dis[i].second > dis[left].second) {
                index++;
                swap(dis[index], dis[i]);
            }
        }
        swap(dis[index], dis[left]);
        quickSort(points, dis, left, index, k - (right - index));
        if (k >= right - index) {
            res.push_back(points[dis[index].first]);
            k--;
        }
        quickSort(points, dis, index + 1, right, k);
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        vector<pair<int, int>> dis;
        for (int i = 0; i < points.size(); ++i) {
            dis.push_back(make_pair(i, points[i][0] * points[i][0] + points[i][1] * points[i][1]));
        }
        quickSort(points, dis, 0, points.size(), K);
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> res = {{3,  3},
                               {5,  -1},
                               {-2, 4}};
    solution.kClosest(res, 2);
    return 0;
}