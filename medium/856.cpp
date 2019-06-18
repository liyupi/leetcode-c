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
#include <ctime>

using namespace std;

class Solution {
public:

    int scoreOfParentheses(string S) {
        stack<char> s;
        int len = S.length();
        int res = 0;
        for (int i = 0; i < len; ++i) {
            if (S[i] == '(') {
                s.push('(');
            } else {
                if (S[i - 1] == '(') {
                    res += (int)pow(2, s.size() - 1);
                }
                s.pop();
            }
        }
        return res;
    }

};

int main() {
    return 0;
}