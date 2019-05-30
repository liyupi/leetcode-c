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
    int shortestDistance(vector<string> &words, string word1, string word2) {
        vector<int> pos1, pos2;
        int size = words.size();
        for (int i = 0; i < size; ++i) {
            if (words[i] == word1) {
                pos1.push_back(i);
            } else if (words[i] == word2) {
                pos2.push_back(i);
            }
        }
        int size1 = pos1.size();
        int size2 = pos2.size();
        int res = 0xfffffff;
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                res = min(res, abs(pos1[i] - pos2[j]));
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}