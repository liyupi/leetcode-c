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
#include <ctime>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preOrderBuild(vector<vector<string>> &res, TreeNode *root, int level, int left, int right) {
        int mid = (left + right) / 2;
        res[level][mid] = to_string(root->val);
        if (root->left) {
            preOrderBuild(res, root->left, level + 1, left, mid - 1);
        }
        if (root->right) {
            preOrderBuild(res, root->right, level + 1, mid + 1, right);
        }
    }

    vector<vector<string>> printTree(TreeNode *root) {
        vector<vector<string>> res;
        int depth = preOrder(root);
        int width = pow(2, depth) - 1;
        for (int i = 0; i < depth; ++i) {
            vector<string> cur;
            for (int j = 0; j < width; ++j) {
                cur.push_back("");
            }
            res.push_back(cur);
        }
        preOrderBuild(res, root, 0, 0, width);
        return res;
    }

    int preOrder(TreeNode *root) {
        int left = 1, right = 1;
        if (root->left) {
            left = preOrder(root->left) + 1;
        }
        if (root->right) {
            right = preOrder(root->right) + 1;
        }
        return max(left, right);
    }
};

int main() {
    Solution solution;
    return 0;
}