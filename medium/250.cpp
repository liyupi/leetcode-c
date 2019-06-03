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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int count = 0;

    int countUnivalSubtrees(TreeNode *root) {
        isUnival(root);
        return count;
    }

    bool isUnival(TreeNode *root) {
        if (!root) {
            return true;
        }
        bool left = isUnival(root->left);
        bool right = isUnival(root->right);
        if (!left || !right) {
            return false;
        }
        if (root->left && root->val != root->left->val) {
            return false;
        }
        if (root->right && root->val != root->right->val) {
            return false;
        }
        count++;
        return true;
    }
};

int main() {
    return 0;
}