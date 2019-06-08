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

    int distributeCoins(TreeNode *root) {
        preOrder(root);
        return res;
    }

    int preOrder(TreeNode *root) {
        int left = 0;
        int tmp;
        if (root->left) {
            tmp = preOrder(root->left);
            left += tmp;
            res += abs(tmp);
        }
        left += root->val - 1;
        if (root->right) {
            tmp = preOrder(root->right);
            left += tmp;
            res += abs(tmp);
        }
        return left;
    }
};

int main() {
    return 0;
}