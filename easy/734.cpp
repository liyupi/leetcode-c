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
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        map<string, set<string>> mmap;
        int size = pairs.size();
        for (int i = 0; i < size; ++i) {
            mmap[pairs[i][0]].insert(pairs[i][1]);
            mmap[pairs[i][1]].insert(pairs[i][0]);
        }
        size = words1.size();
        if(size != words2.size()) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (words1[i] != words2[i] && mmap[words1[i]].find(words2[i]) == mmap[words1[i]].end()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    return 0;
}