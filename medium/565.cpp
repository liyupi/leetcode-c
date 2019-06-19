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
#include <ctime>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int> &nums) {
        bool visited[nums.size()];
        memset(visited, false, sizeof(visited));
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                int pos = i;
                int count = 0;
                while (!visited[pos]) {
                    visited[pos] = true;
                    pos = nums[pos];
                    count++;
                }
                res = max(res, count);
                if (res > nums.size() / 2) {
                    return res;
                }
            }
        }
        return res;
    }
/*    set<int> mset;
    map<int, int> used;

    int arrayNesting(vector<int> &nums) {
        int res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            res = max(res, arrayNesting(nums, i));
        }
        return res;
    }

    int arrayNesting(vector<int> &nums, int pos) {
        if (used[pos]) {
            return used[pos];
        }
        if (mset.count(pos)) {
            return used[pos];
        }
        mset.insert(pos);
        int res =  1 + arrayNesting(nums, nums[pos]);
        used[pos] = res;
        return res;
    }*/
};

int main() {
    return 0;
}