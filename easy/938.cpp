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
    int rangeSumBST(TreeNode *root, int L, int R) {
        if (root == NULL) {
            return 0;
        }
        return rangeSumBST(root->left, L, R)
               + rangeSumBST(root->right, L, R)
               + (root->val >= L && root->val <= R ? root->val : 0);
    }
};

int main() {
    Solution solution;
    return 0;
}