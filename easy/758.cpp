#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * 重叠问题，不需要考虑重叠区间合并，用数组记录某空间是否重叠即可
 */
class Solution {
public:
    string boldWords(vector<string> &words, string S) {
        int size = words.size();
        int len = S.length();
        int bold[len];
        memset(bold, 0, sizeof(bold));
        for (int i = 0; i < size; ++i) {
            int pos = S.find(words[i], 0);
            while (pos != string::npos) {
                for (int j = 0; j < words[i].size(); ++j) {
                    bold[pos + j] = 1;
                }
                pos = S.find(words[i], pos + 1);
            }
        }
        string res;
        bool start = false;
        for (int i = 0; i < len; ++i) {
            if (!bold[i]) {
                if (start) {
                    res += "</b>";
                    start = false;
                }
            } else {
                if (!start) {
                    res += "<b>";
                    start = true;
                }
            }
            res += S[i];
        }
        if (start) {
            res += "</b>";
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> words;
    words.push_back("ab");
    words.push_back("bc");
    solution.boldWords(words, "aabcd");
    return 0;
}