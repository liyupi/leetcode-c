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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return preOrder(preorder, 0, preorder.size());
    }

    TreeNode *preOrder(vector<int> &preorder, int left, int right) {
        if (left == right) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[left]);
        int pos = right;
        for (int i = left + 1; i < right; ++i) {
            if (preorder[i] > root->val) {
                pos = i;
                break;
            }
        }
        root->left = preOrder(preorder, left + 1, pos);
        root->right = preOrder(preorder, pos, right);
        return root;
    }
};

int main() {
    return 0;
}