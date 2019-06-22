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

/**
 * greedy
 */
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while (X != Y) {
            if (X > Y) {
                res += X - Y;
                return res;
            }
            if (Y % 2 == 0) {
                res++;
                Y /= 2;
            } else {
                res += 2;
                Y = (Y + 1) / 2;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}