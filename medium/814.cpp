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
    TreeNode *pruneTree(TreeNode *root) {
        preOrder(root);
        return root;
    }

    bool preOrder(TreeNode *&root) {
        bool left = false, right = false;
        if (root->left) {
            left = preOrder(root->left);
        }
        if (root->right) {
            right = preOrder(root->right);
        }
        if (root->val) {
            return true;
        }
        if (!left && !right) {
            root = NULL;
            return false;
        }
        return true;
    }
};


int main() {
    Solution solution;
    return 0;
}