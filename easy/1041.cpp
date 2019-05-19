#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * 4次循环内看能否回到原点
     * @param instructions
     * @return
     */
    bool isRobotBounded(string instructions) {
        int dir = 0, x = 0, y = 0;
        int dirs[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int len = instructions.length();
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < len; ++i) {
                switch (instructions[i]) {
                    case 'G':
                        x += dirs[dir][0];
                        y += dirs[dir][1];
                        break;
                    case 'L':
                        dir = (dir + 3) % 4;
                        break;
                    case 'R':
                        dir = (dir + 1) % 4;
                        break;
                }
            }
            if (!x && !y) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    return 0;
}