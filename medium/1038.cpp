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
    int val = 0;

    TreeNode *bstToGst(TreeNode *root) {
        inOrder(root);
        return root;
    }

    void inOrder(TreeNode *root) {
        if (root->right) {
            inOrder(root->right);
        }
        int tmp = root->val;
        root->val += val;
        val += tmp;
        if (root->left) {
            inOrder(root->left);
        }
    }
};

int main() {
    return 0;
}