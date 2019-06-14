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
    vector<string> findOcurrences(string text, string first, string second) {
        int len = text.length();
        int pos = 0;
        bool f = false;
        bool s = false;
        vector<string> res;
        for (int i = 0; i < len; ++i) {
            if (i == len - 1) {
                i++;
            }
            if (i == len || text[i] == ' ') {
                string word = text.substr(pos, i - pos);
                pos = i + 1;
                if (s) {
                    res.push_back(word);
                    s = false;
                }
                if (word == first) {
                    f = true;
                    continue;
                }
                if (f) {
                    if (word == second) {
                        s = true;
                    }
                    f = false;
                    continue;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    solution.findOcurrences("alice is a good girl she is a good student", "a", "good");
    return 0;
}