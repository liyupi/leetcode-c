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
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> res(length + 1);
        int size = updates.size();
        for (int i = 0; i < size; ++i) {
            res[updates[i][0]] += updates[i][2];
            res[updates[i][1] + 1] -= updates[i][2];
        }
        int num = 0;
        for (int i = 0; i < length; ++i) {
            num += res[i];
            res[i] = num;
        }
        res.pop_back();
        return res;
    }
};

int main() {
    return 0;
}