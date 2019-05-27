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
    int xdep, ydep, xpar, ypar;

    bool isCousins(TreeNode *root, int x, int y) {
        dfs(root, x, y, 0, root->val);
        return xdep == ydep && xpar != ypar;
    }

    void dfs(TreeNode *root, int x, int y, int dep, int par) {
        if (root == NULL) {
            return;
        }
        if (root->val == x) {
            xpar = par;
            xdep = dep;
        }
        if (root->val == y) {
            ypar = par;
            ydep = dep;
        }
        dfs(root->left, x, y, dep + 1, root->val);
        dfs(root->right, x, y, dep + 1, root->val);
    }
};

int main() {
    Solution solution;
    return 0;
}