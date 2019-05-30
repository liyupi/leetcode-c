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
    bool isStrobogrammatic(string num) {
        string str;
        str.assign(num.rbegin(), num.rend());
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            if (str[i] == '6') {
                if (num[i] != '9') {
                    return false;
                }
            } else if (str[i] == '9') {
                if (num[i] != '6') {
                    return false;
                }
            } else if (str[i] != '0' && str[i] != '1' && str[i] != '8') {
                return false;
            } else if (str[i] != num[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    solution.isStrobogrammatic("69");
    return 0;
}