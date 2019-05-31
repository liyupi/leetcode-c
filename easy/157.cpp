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

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int num = 0;
        while(num < n) {
            int tmp = read4(buf + num);
            if (!tmp) {
                break;
            }
            num += tmp;
        }
        return min(n, num);
    }
};

int main() {
    Solution solution;
    return 0;
}