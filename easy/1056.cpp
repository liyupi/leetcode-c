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
    int map[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};

    bool confusingNumber(int N) {
        int num = 0;
        int oNum = N;
        while(N) {
            int left = N % 10;
            N /= 10;
            if (map[left] == -1) {
                return false;
            }
            num = num * 10 + map[left];
        }
        return num != oNum;
    }
};

int main() {
    Solution solution;
    return 0;
}