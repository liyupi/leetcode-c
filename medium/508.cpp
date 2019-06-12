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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<int, int> mmap;

    vector<int> findFrequentTreeSum(TreeNode *root) {
        getSum(root);
        vector<int> res;
        int maxCount = -1;
        for (auto it = mmap.begin(); it != mmap.end(); ++it) {
            if (it->second > maxCount) {
                res.clear();
                res.push_back(it->first);
                maxCount = it->second;
            } else if (it->second == maxCount) {
                res.push_back(it->first);
            }
        }
        return res;
    }

    int getSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int sum = root->val;
        if (root->left) {
            sum += getSum(root->left);
        }
        if (root->right) {
            sum += getSum(root->right);
        }
        mmap[sum]++;
        return sum;
    }
};


int main() {
    Solution solution;
    return 0;
}