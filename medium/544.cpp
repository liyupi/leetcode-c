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
    int sum;

    string findContestMatch(int n) {
        sum = n + 1;
        return findStr(n, 1, 2);
    }

    string findStr(int n, int left, int next) {
        if (n == 2) {
            stringstream ss;
            ss << '(' << left << ',' << sum - left << ')';
            return ss.str();
        }
        return '(' + findStr(n / 2, left, next * 2) + ',' + findStr(n / 2, next + 1 - left, next * 2) + ')';
    }
};

int main() {
    return 0;
}