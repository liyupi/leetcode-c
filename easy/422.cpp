#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string> &words) {
        int m = words.size();
        for (int i = 0; i < m; ++i) {
            int len = words[i].length();
            if (len > m) {
                return false;
            }
            for (int j = 0; j < len; ++j) {
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<string> words;
    words.push_back("abc");
    words.push_back("b");
    words.push_back("c");
    solution.validWordSquare(words);
    return 0;
}