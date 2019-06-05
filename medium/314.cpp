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
    vector<vector<int>> res;
    int left = 0;
    int right = 0;

    vector<vector<int>> verticalOrder(TreeNode *root) {
        if (!root) {
            return res;
        }
        getRange(root, 0);
        int rootPos = -left;
        int size = right - left + 1;
        // 确认左右边界和根节点位置
        for (int i = 0; i < size; ++i) {
            res.push_back(vector<int>());
        }
        levelOrder(root, rootPos);
        return res;
    }

    void getRange(TreeNode *root, int pos) {
        if (!root) {
            return;
        }
        if (root->left) {
            getRange(root->left, pos - 1);
        }
        left = min(left, pos);
        right = max(right, pos);
        if (root->right) {
            getRange(root->right, pos + 1);
        }
    }

    void levelOrder(TreeNode *root, int rootPos) {
        queue<TreeNode*> nodeQ;
        queue<int> posQ;
        nodeQ.push(root);
        posQ.push(rootPos);
        while(!nodeQ.empty()) {
            TreeNode *node = nodeQ.front();
            int pos = posQ.front();
            nodeQ.pop();
            posQ.pop();
            res[pos].push_back(node->val);
            if (node->left) {
                nodeQ.push(node->left);
                posQ.push(pos - 1);
            }
            if (node->right) {
                nodeQ.push(node->right);
                posQ.push(pos + 1);
            }
        }
    }

};

int main() {
    return 0;
}