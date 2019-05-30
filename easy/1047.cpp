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
    string removeDuplicates(string S) {
        int len = S.length();
        for (int i = 0; i < len - 1; ++i) {
            if (S[i] == S[i + 1]) {
                S.erase(i, 2);
                i = -1;
            }
        }
        return S;
    }
};

int main() {
    Solution solution;
    solution.removeDuplicates("abbaca");
    return 0;
}