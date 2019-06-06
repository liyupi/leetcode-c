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
    map<int, vector<int>> mmap;

    vector<vector<int>> findLeaves(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        postOrder(root);
        for (const auto& entry : mmap) {
            res.push_back(entry.second);
        }
        return res;
    }

    int postOrder(TreeNode *root) {
        int pos = 0;
        if (root->left) {
            pos = postOrder(root->left) + 1;
        }
        if (root->right) {
            pos = max(postOrder(root->right) + 1, pos);
        }
        mmap[pos].push_back(root->val);
        return pos;
    }
};

int main() {
    return 0;
}