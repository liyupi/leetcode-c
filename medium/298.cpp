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
    int res = 0;

    int longestConsecutive(TreeNode *root) {
        longestPath(root);
        return res;
    }

    /**
     * 以每个节点为根的最长连续路径
     * @param root
     * @return
     */
    int longestPath(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int num = 1;
        if (root->left) {
            int tmp = longestPath(root->left);
            if (root->val == root->left->val - 1) {
                num = max(num, tmp + 1);
            }
        }
        if (root->right) {
            int tmp = longestPath(root->right);
            if (root->val == root->right->val - 1) {
                num = max(num, tmp + 1);
            }
        }
        res = max(res, num);
        return num;
    }
};

int main() {
    return 0;
}