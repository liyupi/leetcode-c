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
    vector<int> res;
    int n;

    vector<int> lexicalOrder(int n) {
        this->n = n;
        dfs(0);
        return res;
    }

    void dfs(int num) {
        if (num > n) {
            return;
        }
        if (num) {
            res.push_back(num);
        }
        num *= 10;
        for (int i = 0; i < 10; ++i) {
            if (!num && !i) {
                continue;
            }
            int val = num + i;
            if (val > n) {
                break;
            }
            dfs(num + i);
        }
    }
/*    vector<int> lexicalOrder(int n) {
        set<string> mSet;
        for (int i = 1; i <= n; ++i) {
            mSet.insert(to_string(i));
        }
        vector<int> res;
        for (auto it = mSet.begin(); it != mSet.end() ; ++it) {
            res.push_back(stol(*it));
        }
        return res;
    }*/
};

int main() {
    return 0;
}