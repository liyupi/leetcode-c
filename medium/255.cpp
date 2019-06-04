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
    bool verifyPreorder(vector<int> &preorder) {
        return preorder.size() < 2 || isPreorder(preorder, 0, preorder.size(), preorder[0], false);
    }

    bool isPreorder(vector<int> &preorder, int left, int right, int lastRoot, bool rightSub) {
        if (left >= right - 1) {
            return true;
        }
        int root = preorder[left];
        for (int i = left + 1; i < right; ++i) {
            if (rightSub && preorder[i] < lastRoot) {
                return false;
            }
            if (preorder[i] > root) {
                return isPreorder(preorder, left + 1, i, root, false) && isPreorder(preorder, i, right, root, true);
            }
        }
        return isPreorder(preorder, left + 1, right, root, false);
    }
};

int main() {
    return 0;
}