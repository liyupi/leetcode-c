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
    map<string, vector<char>> mmap;

    bool pyramidTransition(string bottom, vector<string> &allowed) {
        for (int i = 0; i < allowed.size(); ++i) {
            mmap[allowed[i].substr(0, 2)].push_back(allowed[i][2]);
        }
        return dfs(bottom, "");
    }

    bool dfs(string cur, string above) {
        if (cur.length() == 2 && above.length() == 1) {
            return true;
        }
        if (above.length() == cur.length() - 1) {
            return dfs(above, "");
        }
        int pos = above.size();
        string str = cur.substr(pos, 2);
        if (!mmap.count(str)) {
            for (int j = 0; j < mmap[str].size(); ++j) {
                if (dfs(cur, above + mmap[str][j])) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    return 0;
}