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
    TreeNode *pre;

    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *res = NULL;
        if (root->left) {
            res = inorderSuccessor(root->left, p);
            if (res) {
                return res;
            }
        }
        if (pre == p) {
            return root;
        }
        pre = root;
        if (root->right) {
            res = inorderSuccessor(root->right, p);
        }
        return res;
    }
};

int main() {
    return 0;
}