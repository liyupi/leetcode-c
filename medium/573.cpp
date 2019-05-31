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
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int pos = -1;
        int size = nuts.size();
        int maxGap = -100000;
        for (int i = 0; i < size; ++i) {
            int tmp = abs(nuts[i][0] - tree[0]) + abs(nuts[i][1] - tree[1]) - (abs(nuts[i][0] - squirrel[0]) + abs(nuts[i][1] - squirrel[1]));
            if (tmp > maxGap) {
                pos = i;
                maxGap = tmp;
            }
        }
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            int tmp = abs(nuts[i][0] - tree[0]) + abs(nuts[i][1] - tree[1]);
            if (i != pos) {
                tmp *= 2;
            } else {
                tmp += abs(nuts[i][0] - squirrel[0]) + abs(nuts[i][1] - squirrel[1]);
            }
            sum += tmp;
        }
        return sum;
    }
};

int main() {
    return 0;
}