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
    bool isOneEditDistance(string s, string t) {
        int lenS = s.length();
        int lenT = t.length();
        bool flag = true;
        if (lenS > lenT) {
            swap(s, t);
            swap(lenS, lenT);
        }
        if (lenT - lenS > 1) {
            return false;
        }
        for (int i = 0, j = 0; i < lenS; ++i, ++j) {
            if (s[i] != t[j]) {
                if (!flag) {
                    return false;
                }
                flag = false;
                if (lenS < lenT) {
                    i--;
                }
            }
        }
        if (flag) {
            return lenT - lenS == 1;
        }
        return true;
    }
};

int main() {
    return 0;
}