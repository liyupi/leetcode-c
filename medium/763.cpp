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
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    vector<int> partitionLabels(string S) {
        vector<pair<int, int>> v(26);
        int len = S.length();
        for (int i = 0; i < len; ++i) {
            int key = S[i] - 97;
            if (!v[key].first) {
                v[key].first = i + 1;
            }
            v[key].second = i + 1;
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        int right = 1;
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (v[i].first > right) {
                res.push_back(right - count);
                count = right;
            }
            right = max(right, v[i].second);
        }
        res.push_back(len - count);
        return res;
    }
};

int main() {
    Solution solution;
    solution.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}