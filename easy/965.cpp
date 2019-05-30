#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root->left) {
            if (root->val != root->left->val || !isUnivalTree(root->left)) {
                return false;
            }
        }
        if (root->right) {
            if (root->val != root->right->val || !isUnivalTree(root->right)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    solution.removeDuplicates("abbaca");
    return 0;
}