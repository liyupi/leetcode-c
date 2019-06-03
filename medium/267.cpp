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

class Solution {
public:
    unordered_map<char, int> mmap;
    set<string> mset;

    vector<string> generatePalindromes(string s) {
        vector<string> res;
        int len = s.length();
        if (len == 1) {
            res.push_back(s);
            return res;
        }
        for (int i = 0; i < len; ++i) {
            mmap[s[i]]++;
        }
        char odd = 0;
        int i = 0;
        for (auto it = mmap.begin(); it != mmap.end(); ++it) {
            if (it->second & 1) {
                if (!(len & 1) || odd) {
                    return res;
                }
                odd = it->first;
                it->second--;
            }
            it->second /= 2;
        }
        if (odd) {
            string str;
            dfs(str + odd, len);
        } else {
            dfs("", len);
        }
        res.assign(mset.begin(), mset.end());
        return res;
    }

    void dfs(const string &current, const int &len) {
        if (current.length() == len) {
            mset.insert(current);
            return;
        }
        for (auto it = mmap.begin(); it != mmap.end(); ++it) {
            if (it->second) {
                it->second--;
                dfs(it->first + current + it->first, len);
                it->second++;
            }
        }
    }
};

int main() {
    Solution solution;
    solution.generatePalindromes("aabbccc");
    return 0;
}