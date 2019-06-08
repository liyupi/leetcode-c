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
    string customSortString(string S, string T) {
        int pos[S.length()];
        for (int i = 0; i < S.length(); ++i) {
            pos[i] = S[i];
        }
        int count[26] = {0};
        for (int i = 0; i < T.length(); ++i) {
            count[T[i] - 97]++;
        }
        string res;
        for (int i = 0; i < S.length(); ++i) {
            res.append(count[pos[i] - 97], pos[i]);
            count[pos[i] - 97] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i]) {
                res.append(count[i], i + 97);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}