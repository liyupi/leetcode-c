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
    bool isValid(string S) {
        int count[3] = {0};
        int len = S.length();
        if (len % 3) {
            return false;
        }
        stack<char> mstack;
        char pre, prepre;
        for (int i = 0; i < len; ++i) {
            if (mstack.size() >= 2) {
                pre = mstack.top();
                mstack.pop();
                prepre = mstack.top();
                if (prepre == 'a' && pre == 'b' && S[i] == 'c') {
                    mstack.pop();
                    continue;
                }
                mstack.push(pre);
                mstack.push(S[i]);
            } else {
                mstack.push(S[i]);
            }
        }
        return mstack.empty();
    }
};

int main() {
    return 0;
}