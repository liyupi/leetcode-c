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
    set<string> res;

    vector<string> generateAbbreviations(string word) {
        dfs(word, 0);
        vector<string> ans;
        for (auto it = res.begin(); it != res.end(); ++it) {
            stringstream str;
            int len = (*it).length();
            int sum = 0;
            for (int i = 0; i < len; ++i) {
                char c = (*it)[i];
                if (c == '1') {
                    sum++;
                } else {
                    if (sum) {
                        str << sum;
                        sum = 0;
                    }
                    str << c;
                }
            }
            if (sum) {
                str << sum;
            }
            ans.push_back(str.str());
        }
        return ans;
    }

    void dfs(const string &word, int pos) {
        string str = word;
        res.insert(str);
        int len = word.length();
        if (pos == len) {
            return;
        }
        str[pos] = word[pos];
        dfs(str, pos + 1);
        str[pos] = '1';
        dfs(str, pos + 1);
    }
};

int main() {
    return 0;
}