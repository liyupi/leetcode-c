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
    vector<vector<int>> indexPairs(string text, vector<string> &words) {
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); ++i) {
            int pos = 0;
            while ((pos = text.find(words[i], pos)) != string::npos) {
                vector<int> v = {pos, pos + (int) words[i].length() - 1};
                res.push_back(v);
                pos++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}