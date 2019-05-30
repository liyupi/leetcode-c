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
    bool validWordAbbreviation(string word, string abbr) {
        int len = abbr.length();
        int num = 0;
        int i = 0;
        for (int j = 0; j < len; ++j) {
            if (isalpha(abbr[j])) {
                if (num) {
                    i += num;
                    num = 0;
                }
                if (word[i] != abbr[j]) {
                    return false;
                }
                i++;
            } else {
                if (num == 0 && abbr[j] == 48) {
                    return false;
                }
                num = num * 10 + abbr[j] - 48;
            }
        }
        return i + num == word.length();
    }
};

int main() {
    Solution solution;
    return 0;
}