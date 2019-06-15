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
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length()) {
            return gcdOfStrings(str2, str1);
        }
        if (str2 == "") {
            return str1;
        }
        int len = str2.length();
        int i;
        for (i = 0; i < len; ++i) {
            if (str1[i] != str2[i]) {
                return "";
            }
        }
        return gcdOfStrings(str2, str1.substr(i, str1.length() - i));
    }
};

int main() {
    Solution solution;
    solution.gcdOfStrings("ababab", "abab");
    return 0;
}