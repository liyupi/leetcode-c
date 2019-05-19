#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> mstack;
        string res;
        int len = S.length();
        for (int i = 0; i < len; ++i) {
            char c = S[i];
            if (c == '(') {
                if (!mstack.empty()) {
                    res += c;
                }
                mstack.push(c);
            } else {
                mstack.pop();
                if (!mstack.empty()) {
                    res += c;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}