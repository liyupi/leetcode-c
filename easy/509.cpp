#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int fib(int N) {
        int pre = 0;
        int next = 1;
        for (int i = 0; i < N; ++i) {
            int tmp = next;
            next = pre + next;
            pre = tmp;
        }
        return pre;
    }
};

int main() {
    Solution solution;
    return 0;
}