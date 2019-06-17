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
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        TreeNode *node = new TreeNode(val);
        if (root->val < val) {
            node->left = root;
            return node;
        }
        if (!root->right) {
            root->right = node;
            return root;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};

int main() {
    Solution solution;
    return 0;
}