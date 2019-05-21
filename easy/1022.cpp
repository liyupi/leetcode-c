#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sum = 0;

    void dfs(TreeNode *root, int val) {
        val += root->val;
        if (!root->left && !root->right) {
            sum += val;
        }
        val <<= 1;
        if (root->left) {
            dfs(root->left, val);
        }
        if (root->right) {
            dfs(root->right, val);
        }
    }

    int sumRootToLeaf(TreeNode *root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};

int main() {
    Solution solution;
    return 0;
}