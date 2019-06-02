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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            return root;
        }
        TreeNode* pos = root;
        TreeNode* pre = root;
        while(pos->left) {
            pre = pos;
            pos = pos->left;
        }
        pos->left = pre->right;
        pre->left = pre->right = NULL;
        pos->right = upsideDownBinaryTree(root);
        return pos;
    }
};

int main() {
    return 0;
}