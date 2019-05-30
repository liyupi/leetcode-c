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
    vector<string> generatePossibleNextMoves(string s) {
        int len = s.length() - 1;
        vector<string> res;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                res.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return res;
    }
};

int main() {
    return 0;
}