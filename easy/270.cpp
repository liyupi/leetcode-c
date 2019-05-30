#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode *root, double target) {
        int minNum = root->val;
        double val = abs(target - minNum);
        int leftMin = minNum, rightMin = minNum;
        double leftVal = val, rightVal = val;
        if (root->left) {
            leftMin = closestValue(root->left, target);
            leftVal = abs(leftMin - target);
        }
        if (root->right) {
            rightMin = closestValue(root->right, target);
            rightVal = abs(rightMin - target);
        }
        if (rightVal < leftVal) {
            leftMin = rightMin;
            leftVal = rightVal;
        }
        if (leftVal < val) {
            minNum = leftMin;
        }
        return minNum;
    }
};

int main() {
    Solution solution;
    return 0;
}